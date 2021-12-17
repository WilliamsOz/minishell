/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:08:42 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/17 19:08:53 by wiozsert         ###   ########.fr       */
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
