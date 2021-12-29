/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lk_destroyer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:29:51 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/29 02:05:06 by user42           ###   ########.fr       */
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
