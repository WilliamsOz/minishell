/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metacharacter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:05:21 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/05 16:51:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*get_metacharacter(t_dlk_list *dlk, char c, int *ptr_i, char *str)
{
	int	i;

	i = *ptr_i;
	dlk->is_metacharacter = 1;
	if (str[i] == LOWER_RAFTER && str[i + 1] == LOWER_RAFTER)
	{
		dlk->here_doc = 1;
		*ptr_i += 2;
		return (dlk);
	}
	if (c == LOWER_RAFTER)
		dlk->lower_rafter = 1;
	else if (c == UPPER_RAFTER)
		dlk->upper_rafter = 1;
	else if (c == PIPELINE)
		dlk->pipeline = 1;
	*ptr_i += 1;
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
	dlk->here_doc = 0;
	dlk->lower_rafter = 0;
	dlk->upper_rafter = 0;
	dlk->pipeline = 0;
	dlk->is_metacharacter = 0;
	dlk->quote_ind = 0;
	dlk->simple_quote = 0;
	dlk->double_quote = 0;
	dlk->pipeline_next_to_pipeline = 0;
	return (dlk);
}
