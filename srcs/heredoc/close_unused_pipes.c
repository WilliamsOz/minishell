/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:13:25 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:32:13 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_dlk_list	*get_last_hd(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	tmp = dlk;
	keep = NULL;
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1)
			keep = tmp;
		tmp = tmp->next;
	}
	if (keep != NULL && keep->next != NULL)
	{
		close(keep->heredoc_pipe[1]);
		keep->heredoc_pipe[1] = -1;
	}
	return (keep);
}
