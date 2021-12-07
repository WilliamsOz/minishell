/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_upper_rafter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:24:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/07 12:36:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_double_upper_rafter(t_dlk_list *dlk)
{
	if (dlk->previous != NULL && dlk->previous->token == NULL)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `>>'\n", 2);
		return (TRUE);
	}
	else if (dlk->next == NULL)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n",
			2);
		return (TRUE);
	}
	return (FALSE);
}
