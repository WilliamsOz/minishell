/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lk_destroyer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:29:51 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 12:51:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*double_lk_destroyer(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	while (dlk != NULL)
	{
		tmp = dlk;
		dlk = dlk->next;
		if (tmp->token != NULL)
		{
			free(tmp->token);
			tmp->token = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
	return (dlk);
}
