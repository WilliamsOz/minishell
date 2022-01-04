/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_one_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:35:32 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 15:55:16 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*leave_one_token(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->token != NULL)
		{
			keep = tmp;
			tmp = tmp->next;
			while (tmp != NULL && tmp->token != NULL)
			{
				keep->next = tmp->next;
				free(tmp);
				tmp = NULL;
				tmp = keep->next;
			}
			tmp = keep->next;
		}
		else
			tmp = tmp->next;
	}
	return (dlk);
}
