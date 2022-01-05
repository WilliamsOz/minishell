/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_rafter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:37:44 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:38:13 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	lower_rafter_errors(t_dlk_list *dlk)
{
	if (dlk->next == NULL)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n",
			2);
		return (TRUE);
	}
	else if (dlk->next->upper_rafter == 1)
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
