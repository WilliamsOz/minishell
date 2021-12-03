/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lk_destroyer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:29:51 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/03 18:41:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	double_lk_destroyer(t_dlk_list *d_lk)
{
	t_dlk_list	*tmp;

	while (d_lk != NULL)
	{
		tmp = d_lk;
		d_lk = d_lk->next;
		if (tmp->token != NULL)
			free(tmp->token);
		free(tmp);
	}
}
