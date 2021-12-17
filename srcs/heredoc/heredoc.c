/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:07:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/17 19:35:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*rd_hd(t_minishell *m, t_dlk_list *dlk, char **env, int ef)
{
	char	*buffer;

	while (ef > 0)
	{
		buffer = read_on_hd_pipe(m, buffer, env, &ef);
		if (signal_handler == SIGINT)
			break ;
		if (ef == 0)
			eof_called(m, dlk);
		if (ef > 0 && ft_strcmp(dlk->limiter, buffer) == TRUE)
		{
			dlk = end_called(dlk, buffer);
			return (dlk);
		}
		else if (ef > 0)
			write_hd_inside_pipe(dlk, buffer, &dlk->hd_line_count);
	}
	return (dlk);
}

static t_dlk_list	*get_heredoc(t_minishell *m, t_dlk_list *dlk, char **env)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1 && tmp->limiter != NULL)
		{
			tmp->hd_line_count = 1;
			tmp = rd_hd(m, tmp, env, 1);
		}
		tmp = tmp->next;
	}
	dlk = close_ununsed_pipes(dlk);
	return (dlk);
}

t_dlk_list	*heredoc(t_minishell *m, t_dlk_list *dlk, char **env)
{
	m->sa.sa_handler = handle_hd_sigint;
	dlk = init_heredoc_pipes(m, dlk, 0);
	dlk = get_heredoc(m, dlk, env);
	return (dlk);
}
