/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_rafter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:37:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/14 16:51:27 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_ambiguous_(t_dlk_list *dlk, char **env)
{
	if (dlk->next->token[0] == '$' && dlk->next->token[1] != '\0'
		&& existing_expand(dlk->next->token + 0 + 1, env, 0, 0) == FALSE)
		return (TRUE);
	return (FALSE);
}

static int	_existing_(t_minishell *m, t_dlk_list *dlk, char **env)
{
	char	*tmp;
	int		fd;

	tmp = trim(m, dlk->next->token, -1, env);
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(tmp, 2);
		free(tmp);
		return (FALSE);
	}
	close (fd);
	return (TRUE);
}

int	lower_rafter_errors(t_minishell *m, t_dlk_list *dlk, char **env)
{
	if (dlk->next == NULL)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n",
			2);
		return (TRUE);
	}
	if (dlk->next->token != NULL && _ambiguous_(dlk, env) == TRUE)
		printf("bash: %s: ambiguous redirect\n", dlk->next->token);
	else if (dlk->next->upper_rafter == 1)
		ft_putstr_fd("bash: syntax error near unexpected token `>'\n", 2);
	else if (dlk->next->lower_rafter == 1)
		ft_putstr_fd("bash: syntax error near unexpected token `<'\n", 2);
	else if (dlk->next->double_upper_rafter == 1)
		ft_putstr_fd("bash: syntax error near unexpected token `>>'\n", 2);
	else if (dlk->next->here_doc == 1)
		ft_putstr_fd("bash: syntax error near unexpected token `<<'\n", 2);
	else if (dlk->next->token != NULL && _existing_(m, dlk, env) == FALSE)
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		return (FALSE);
	return (TRUE);
}
