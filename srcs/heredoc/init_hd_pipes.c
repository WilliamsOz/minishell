/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hd_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:22:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 13:11:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*__init_heredoc_pipes__(t_minishell *m, t_dlk_list *dlk, int ind)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	tmp = dlk;
	dlk = memset_heredoc_pipe(dlk);
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1)
		{
			ind = pipe(tmp->heredoc_pipe);
			if (ind == -1)
				pipe_failed(m);
			tmp->limiter = tmp->next->token;
			keep = tmp->next->next;
			free(tmp->next);
			tmp->next = keep;
		}
		tmp = tmp->next;
	}
	return (dlk);
}
