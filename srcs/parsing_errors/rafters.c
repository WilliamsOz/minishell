/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rafters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:30:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/07 15:33:37 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	__lower_rafter_errors__(t_dlk_list *dlk)
{
	if (dlk->next == NULL)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n",
			2);
		return (TRUE);
	}
	else if (dlk->next != NULL)
	{
		if (dlk->next->upper_rafter == 1)
			ft_putstr_fd("bash: syntax error near unexpected token `>'\n", 2);
		else if (dlk->next->lower_rafter == 1)
			ft_putstr_fd("bash: syntax error near unexpected token `<'\n", 2);
		else if (dlk->next->double_upper_rafter == 1)
			ft_putstr_fd("bash: syntax error near unexpected token `>>'\n", 2);
		else if (dlk->next->here_doc == 1)
			ft_putstr_fd("bash: syntax error near unexpected token `<<'\n", 2);
		else
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

static int	_upper_rafter_errors_(t_dlk_list *dlk)
{
	if (dlk->next == NULL)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n",
			2);
		return (TRUE);
	}
	else if (dlk->next != NULL)
	{
		if (dlk->next->upper_rafter == 1)
			ft_putstr_fd("bash: syntax error near unexpected token `>'\n", 2);
		else if (dlk->next->lower_rafter == 1)
			ft_putstr_fd("bash: syntax error near unexpected token `<'\n", 2);
		else if (dlk->next->double_upper_rafter == 1)
			ft_putstr_fd("bash: syntax error near unexpected token `>>'\n", 2);
		else if (dlk->next->here_doc == 1)
			ft_putstr_fd("bash: syntax error near unexpected token `<<'\n", 2);
		else
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

int	check_rafter_errors(t_dlk_list *dlk)
{
	if (dlk->lower_rafter == 1 && __lower_rafter_errors__(dlk) == 1)
		return (TRUE);
	else if (dlk->upper_rafter == 1 && _upper_rafter_errors_(dlk) == 1)
		return (TRUE);
	return (FALSE);
}
