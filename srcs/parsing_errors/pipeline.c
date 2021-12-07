/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:26:40 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/07 16:46:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_pipeline_link_to_cmd(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->pipeline == 1 && tmp->next == NULL &&
			tmp->previous != NULL && tmp->previous->token != NULL)
		{
			ft_putstr_fd("Command after pipeline is missing\n", 2);
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

int	check_pipeline_errors(t_dlk_list *tmp)
{
	if (tmp->pipeline_next_to_pipeline == 1)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `||'\n", 2);
		return (TRUE);
	}
	else if (tmp->previous == NULL ||
		(tmp->previous != NULL && tmp->previous->token == NULL))
	{
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
		return (TRUE);
	}
	else if (tmp->next != NULL && tmp->next->token == NULL)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n",
			2);
		return (TRUE);
	}
	return (FALSE);
}
