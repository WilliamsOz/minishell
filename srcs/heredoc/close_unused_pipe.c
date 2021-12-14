/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:13:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/14 17:17:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*close_unused_pipe(t_dlk_list *dlk)
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
	tmp = dlk;
	while (tmp != keep)
	{
		if (tmp->here_doc == 1)
			close(tmp->heredoc_pipe[0]);
		tmp = tmp->next;
	}
	return (dlk);
}
