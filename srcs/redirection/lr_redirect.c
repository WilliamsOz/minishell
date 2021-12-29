/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lr_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:14:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/29 02:02:32 by user42           ###   ########.fr       */
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
	return (dlk);
}

t_minishell *redirect_l_r(t_minishell *m, t_dlk_list **dlk, t_cmd **cmd)
{
	(*dlk)->fd_file = open((*dlk)->next->token, O_RDWR);
	if ((*cmd)->input != STDIN_FILENO)
		close((*cmd)->input);
	(*cmd)->input = (*dlk)->fd_file;
	if ((*dlk)->previous == NULL)
	{
		(*dlk) = previous_null((*dlk));
		m->d_lk = (*dlk);
	}
	else
		(*dlk) = previous_not_null((*dlk));
	m->d_lk = *dlk;
	m->cmd = *cmd;
	return (m);
}
