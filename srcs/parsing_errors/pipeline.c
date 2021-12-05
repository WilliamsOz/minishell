/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:26:40 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/05 15:25:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*check_pipeline_errors(t_minishell *minishell, t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->pipeline_next_to_pipeline == 1)
			minishell->parsing_err->pipeline_next_to_pipeline = 1;
		else if (tmp->pipeline == 1 &&
			(tmp->previous->token == NULL ||tmp->next->token == NULL))
			minishell->parsing_err->pipeline_next_to_null = 1;
		tmp = tmp->next;
	}
	return (minishell);
}
