/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_ur_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:29:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/26 15:29:24 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*redirect_d_ur(t_dlk_list *dlk, t_cmd *cmd)
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
	cmd->output = dlk->fd_file;
	return (dlk);
}
