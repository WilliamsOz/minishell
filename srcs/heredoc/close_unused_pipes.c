/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:13:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 14:28:06 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*close_ununsed_pipes(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1)
			keep = tmp;
		tmp = tmp->next;
	}
	close(keep->heredoc_pipe[1]);
	keep->heredoc_pipe[1] = -1;
	tmp = dlk;
	while (tmp != keep)
	{
		if (tmp->here_doc == 1)
		{
			close(tmp->heredoc_pipe[0]);
			close(tmp->heredoc_pipe[1]);
			tmp->heredoc_pipe[0] = -1;
			tmp->heredoc_pipe[1] = -1;
		}
		tmp = tmp->next;
	}
	return (dlk);
}
