/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_interpretation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:13:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/04 11:20:10 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_minishell	*__interpretation_errors_found__(t_minishell *minishell)
{
	minishell->line = free_line(minishell->line);
	return (minishell);
}

t_minishell			*check_interpretation_errors(t_minishell *minishell)
{
	if (unspecified_char(minishell->line) == TRUE)
	{
		ft_putstr_fd("Unspecified char detected\n", 2);
		minishell = __interpretation_errors_found__(minishell);
	}
	else if (quote_not_closed(minishell->parsing_err, 0, minishell->line) == TRUE)
	{
		ft_putstr_fd("Unclosed cote detected\n", 2);
		minishell = __interpretation_errors_found__(minishell);
	}
	return (minishell);
}
