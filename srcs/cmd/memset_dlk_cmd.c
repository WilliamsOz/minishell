/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_dlk_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:14:12 by user42            #+#    #+#             */
/*   Updated: 2022/01/04 12:53:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*memset_dlk_cmd(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		tmp->cmd = NULL;
		tmp = tmp->next;
	}
	return (dlk);
}
