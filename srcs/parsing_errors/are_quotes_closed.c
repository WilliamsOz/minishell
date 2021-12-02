/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_quotes_closed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:58:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 13:32:49 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	are_quotes_closed(t_minishell minishell, int i)
{
	minishell.simple_cote = 0;
	minishell.double_cote = 0;
	while (minishell.line[i] != '\0')
	{
		if (minishell.line[i] == 39)
			minishell.simple_cote++;
		else if (minishell.line[i] == 34)
			minishell.double_cote++;
		i++;
	}
	if (minishell.simple_cote % 2 != 0 || minishell.double_cote % 2 != 0)
	{
		ft_putstr_fd("Unclosed quotes detected\n", 2);
		minishell.line = free_line(minishell.line);
	}
	return (minishell);
}