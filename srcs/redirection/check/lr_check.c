/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:44:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 16:19:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	missing_read_permission(char *file)
{
	int	ind;

	ind = access(file, R_OK);
	if (ind == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		signal_handler = 1;
		return (TRUE);
	}
	return (FALSE);
}

static int	missing_file(char *file)
{
	int	ind;

	ind = access(file, F_OK);
	if (ind == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		signal_handler = 1;
		return (TRUE);
	}
	return (FALSE);
}

int	lr_bad_redirection(t_minishell *m, t_dlk_list *dlk)
{
	char	*file;

	if (dlk->next->token[0] == '$' && dlk->next->token[1] != '\0'
		&& existing_expand(dlk->next->token + 1, m->env, 0) == FALSE)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(dlk->next->token, 2);
		ft_putstr_fd(": ambiguous redirect\n", 2);
		signal_handler = 1;
		return (TRUE);
	}
	if (dlk->next->token[0] == '$' && dlk->next->token[1] == '\0')
		file = dlk->next->token;
	else
		file = trim(m, dlk->next->token, -1);
	if (missing_file(file) == TRUE || missing_read_permission(file) == TRUE)
	{
		signal_handler = 1;
		free(file);
		return (TRUE);
	}
	free(file);
	return (FALSE);
}
