/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rafters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:30:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/07 12:15:51 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_lower_rafter_missing_input_(t_dlk_list *dlk)
{
	if (dlk->next == NULL)
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n",
			2);
	else if (dlk->next->token == NULL && dlk->next->pipeline == 0)
		ft_putstr_fd("bash: syntax error near unexpected token `<'\n", 2);
	if (dlk->next == NULL ||
		(dlk->next->token == NULL && dlk->next->pipeline == 0))
		return (TRUE);
	return (FALSE);
}

static int	_lower_rafter_missing_output_(t_dlk_list *dlk)
{
	if (dlk->next == NULL)
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n",
			2);
	else if (dlk->next->token == NULL && dlk->next->pipeline == 0)
		ft_putstr_fd("bash: syntax error near unexpected token `>'\n", 2);
	if (dlk->next == NULL ||
		(dlk->next->token == NULL && dlk->next->pipeline == 0))
		return (TRUE);
	return (FALSE);
}

static int	_upper_rafter_missing_input_(t_dlk_list *dlk)
{
	if (dlk->previous != NULL && dlk->previous->token == NULL)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `<'\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

static int	_upper_rafter_missing_output_(t_dlk_list *dlk)
{
	if (dlk->previous != NULL && dlk->previous->token == NULL)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `>'\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

int	check_rafter_errors(t_dlk_list *dlk)
{
	if (dlk->lower_rafter == 1 && _lower_rafter_missing_input_(dlk) == 1)
		return (TRUE);
	else if (dlk->lower_rafter == 1 && _lower_rafter_missing_output_(dlk) == 1)
		return (TRUE);
	else if (dlk->upper_rafter == 1 && _upper_rafter_missing_input_(dlk) == 1)
		return (TRUE);
	else if (dlk->upper_rafter == 1 && _upper_rafter_missing_output_(dlk) == 1)
		return (TRUE);
	return (FALSE);
}
