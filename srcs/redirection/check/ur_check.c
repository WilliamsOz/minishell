/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ur_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:59:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/27 15:05:13 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	missing_read_permission(char *file)
{
	int	fd;
	int	ind;

	ind = access(file, F_OK);
	if (ind != -1)
	{
		fd = open(file, O_RDWR);
		if (fd == -1)
		{
			ft_putstr_fd("bash: ", 2);
			ft_putstr_fd(file, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			signal_handler = 1;
			return (TRUE);
		}
		close(fd);
	}
	return (FALSE);
}

static int	is_directory(char *file)
{
	struct stat	buf;
	int			ind;

	ind = access(file, F_OK);
	if (ind == -1)
		return (FALSE);
	stat(file, &buf);
	if (S_ISDIR(buf.st_mode) == 1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		signal_handler = 1;
		return (TRUE);
	}
	return (FALSE);
}

static int	ambiguous_redirect(t_minishell *m, t_dlk_list *dlk)
{
	if (dlk->next->token[0] == '$' && dlk->next->token[1] != '\0'
		&& existing_expand(dlk->next->token + 1, m->env, 0) == FALSE)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(dlk->next->token, 2);
		ft_putstr_fd(": ambiguous redirect\n", 2);
		signal_handler = 1;
		return (TRUE);
	}
	return (FALSE);
}

int	ur_bad_redirection(t_minishell *m, t_dlk_list *dlk)
{
	char	*file;

	if (ambiguous_redirect(m, dlk) == TRUE)
		return (TRUE);
	if (dlk->next->token[0] == '$' && dlk->next->token[1] == '\0')
		file = dlk->next->token;
	else
		file = trim(m, dlk->next->token, -1);
	if (is_directory(file) == TRUE || missing_read_permission(file) == TRUE)
	{
		signal_handler = 1;
		free(file);
		return (TRUE);
	}
	free(file);
	return (FALSE);
}
