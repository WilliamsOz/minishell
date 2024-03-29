/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_d_lk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:14:30 by user42            #+#    #+#             */
/*   Updated: 2021/12/24 18:18:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*hd_prepare_dlk(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	tmp = dlk->next;
	keep = tmp->next;
	dlk->limiter = tmp->token;
	free(tmp);
	dlk->next = keep;
	dlk->heredoc_pipe[0] = -1;
	dlk->heredoc_pipe[1] = -1;
	return (dlk);
}
