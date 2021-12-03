/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metacharacter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:05:21 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/03 18:25:27 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*get_metacharacter(t_dlk_list *dlk, char c, int **ptr_i)
{
	if (c == LOWER_RAFTER)
		dlk->lower_rafter = 1;
	else if (c == UPPER_RAFTER)
		dlk->upper_rafter = 1;
	else if (c == PIPELINE)
		dlk->pipeline = 1;
	**ptr_i += 1;
	return (dlk);
}

int			is_metacharacter(char c)
{
	if (c == LOWER_RAFTER || c == UPPER_RAFTER || c == PIPELINE)
		return (1);
	return (0);
}

t_dlk_list	*init_dlk_metacharacter(t_dlk_list *dlk)
{
	dlk->next = NULL;
	dlk->token = NULL;
	dlk->lower_rafter = 0;
	dlk->upper_rafter = 0;
	dlk->pipeline = 0;
	return (dlk);
}
