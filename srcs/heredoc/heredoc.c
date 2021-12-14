/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:07:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/14 17:22:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_dlk_list	*rd_hd(t_minishell *m, t_dlk_list *dlk, char **env, int ef)
{
	char	*buffer;

	while (ef > 0)
	{
		buffer = read_on_hd_pipe(m, buffer, env, &ef);
		if (ef == 0 || ft_strcmp(dlk->limiter, buffer) == TRUE) //ajouter signal ici
		{
			dlk = end_called(dlk, buffer);
			return (dlk);
		}
		else
			write_hd_inside_pipe(dlk, buffer);
	}
	return (dlk);
}

static t_dlk_list	*get_heredoc(t_minishell *m, t_dlk_list *dlk, char **env)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1)
			tmp = rd_hd(m, tmp, env, 1);
		tmp = tmp->next;
	}
	dlk = close_unused_pipe(dlk);
	return (dlk);
}

t_dlk_list	*heredoc(t_minishell *m, t_dlk_list *dlk, char **env)
{
	dlk = __init_heredoc_pipes__(m, dlk, 0);
	dlk = get_heredoc(m, dlk, env);
	return (dlk);
}