/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_ur_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:29:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/29 11:45:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_dlk_list	*previous_null(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	dlk = dlk->next;
	free(tmp);
	tmp = dlk;
	dlk = dlk->next;
	free(tmp->token);
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
	free(tmp);
	dlk->next = keep;
	tmp = keep;
	keep = keep->next;
	free(tmp->token);
	free(tmp);
	dlk->next = keep;
	if (keep != NULL)
		keep->previous = dlk;
	return (dlk);
}

t_minishell	*redirect_d_ur(t_minishell *m, t_dlk_list **dlk, t_cmd **tmp_cmd)
{
	if ((*tmp_cmd)->output != STDOUT_FILENO)
		close((*tmp_cmd)->output);
	(*dlk)->fd_file = open((*dlk)->next->token, O_RDWR | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	(*tmp_cmd)->output = (*dlk)->fd_file;
	if ((*dlk)->previous == NULL)
	{
		(*dlk) = previous_null((*dlk));
		m->d_lk = (*dlk);
	}
	else
		(*dlk) = previous_not_null((*dlk));
	m->d_lk = *dlk;
	m->cmd = *tmp_cmd;
	return (m);
}
