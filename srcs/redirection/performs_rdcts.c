/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performs_rdcts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:22:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/25 13:41:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_dlk_list	*redirect_ur(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	keep = dlk->next->next;
	tmp = dlk->next;
	dlk->file = tmp->token;
	free(tmp);
	dlk->next = keep;
	dlk->fd_file = open(dlk->file, O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return (dlk);
}

static t_dlk_list	*init_dlk_redirect(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		tmp->file = NULL;
		tmp->fd_file = -1;
		tmp = tmp->next;
	}
	return (dlk);
}

static t_dlk_list	*redirect_d_ur(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	keep = dlk->next->next;
	tmp = dlk->next;
	dlk->file = tmp->token;
	free(tmp);
	dlk->next = keep;
	dlk->fd_file = open(dlk->file, O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return (dlk);
}

t_dlk_list	*performs_redirection(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	dlk = init_dlk_redirect(dlk);
	while (tmp != NULL)
	{
		if (tmp->upper_rafter == 1)
			tmp = redirect_ur(tmp);
		else if (tmp->double_upper_rafter == 1)
			tmp = redirect_d_ur(tmp);
		tmp = tmp->next;
	}
	
	return (dlk);
}
