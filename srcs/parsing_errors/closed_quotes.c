/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:58:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/05 17:16:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*are_quotes_closed(t_minishell*minishell, int i, char *line)
{
	t_parsing_err	*parsing_err;

	parsing_err = parsing_err_creator();
	parsing_err->simple_cote = 0;
	parsing_err->double_cote = 0;
	while (line[i] != '\0')
	{
		if (line[i] == SIMPLE_COTE)
			parsing_err->simple_cote++;
		else if (line[i] == DOUBLE_COTE)
			parsing_err->double_cote++;
		i++;
	}
	if (parsing_err->simple_cote % 2 != 0 ||
		parsing_err->double_cote % 2 != 0)
	{
		ft_putstr_fd("Unclosed Quotes\n", 2);
		minishell_destroyer(minishell);
		parsing_err_destroyer(parsing_err);
	}
	return (minishell);
}
