/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:19:19 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/30 13:44:32 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_dlk_list	*previous_null(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	dlk = dlk->next;
	free(tmp->limiter);
	free(tmp);
	if (dlk != NULL)
		dlk->previous = NULL;
	return (dlk);
}

static t_dlk_list	*previous_not_null(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	tmp = dlk;
	keep = dlk->next;
	dlk = dlk->previous;
	free(tmp->limiter);
	free(tmp);
	dlk->next = keep;
	if (keep != NULL)
		keep->previous = dlk;
	return (dlk);
}

t_minishell	*redirect_hd(t_minishell *m, t_dlk_list **dlk, t_cmd **cmd)
{
	(*cmd)->input = (*dlk)->heredoc_pipe[0];
	if ((*dlk)->previous == NULL)
	{
		(*dlk) = previous_null((*dlk));
		m->d_lk = (*dlk);
	}
	else
		(*dlk) = previous_not_null((*dlk));
	return (m);
}
