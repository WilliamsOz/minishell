/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_failed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:14:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/14 16:52:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	close_heredoc_pipes(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->heredoc_pipe[0] != -1)
			close(tmp->heredoc_pipe[0]);
		if (tmp->heredoc_pipe[1] != -1)
			close(tmp->heredoc_pipe[1]);
		tmp = tmp->next;
	}
}

void	pipe_failed(t_minishell *minishell)
{
	strerror(errno);
	close_heredoc_pipes(minishell->d_lk);
	minishell = destroy_all_data(minishell);
	exit (EXIT_FAILURE);
}
