/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_errros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:26:40 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/04 12:16:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	__token_null_previous_or_after__(t_dlk_list *tmp)
{
	if (tmp->pipeline == 1)
	{
		 // pipe at begining
		 // attention si une pipe est a la fin c'est le bash rentre '>'
		if (tmp->previous == NULL || tmp->next == NULL)
		{
			ft_putstr_fd("", 2)
			return (1);
		}
	}
	return (0);
}

int	check_pipeline_errors(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (__token_null_previous_or_after__(tmp) == 1)
			return (1);
	}
	return (0);
}
