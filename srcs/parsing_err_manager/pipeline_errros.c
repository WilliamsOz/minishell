/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_errros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:26:40 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/04 16:28:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// static int	__token_null_previous_or_after__(t_dlk_list *tmp)
// {
// 	if (tmp->pipeline == 1)
// 	{
// 		if (tmp->previous == NULL)
			
// 	}
// 	return (0);
// }

int	check_pipeline_errors(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		// if (__token_null_previous_or_after__(tmp) == 1)
		// 	return (1);
		tmp = tmp->next;
	}
	return (0);
}
