/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:26:40 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/07 12:43:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_pipeline_errors(t_dlk_list *tmp)
{
	if (tmp->pipeline_next_to_pipeline == 1)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `||'\n", 2);
		return (TRUE);
	}
	else if (tmp->pipeline == 1 &&
		(tmp->previous == NULL || tmp->next == NULL ||
		tmp->previous->token == NULL || tmp->next->token == NULL))
	{
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
		return (TRUE);
	}
	return (FALSE);
}
