/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:58:29 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 12:42:01 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	__get_end__(char *line, int i, int *s_cote, int *d_cote)
{
	if (line[i] == SIMPLE_COTE)
		*s_cote += 1;
	else
		*d_cote += 1;
	i++;
	while (line[i] != '\0' && (*s_cote == 1 || *d_cote == 1))
	{
		if (*s_cote == 1 && line[i] == SIMPLE_COTE)
			*s_cote -= 1;
		else if (*d_cote == 1 && line[i] == DOUBLE_COTE)
			*d_cote -= 1;
		i++;
	}
	return (i);
}

t_minishell	*are_quotes_closed(t_minishell*minishell, int i, char *line)
{
	minishell->parsing_err->simple_cote = 0;
	minishell->parsing_err->double_cote = 0;
	while (line[i] != '\0')
	{
		if (line[i] == SIMPLE_COTE || line[i] == DOUBLE_COTE)
		{
			i = __get_end__(line, i, &minishell->parsing_err->simple_cote,
				&minishell->parsing_err->double_cote);
		}
		else
			i++;
	}
	if (minishell->parsing_err->simple_cote == 1
		|| minishell->parsing_err->double_cote == 1)
	{
		ft_putstr_fd("Unclosed Quotes\n", 2);
		add_history(minishell->line);
		minishell->line = free_line(minishell->line);
		minishell->parsing_err = parsing_err_destroyer(minishell->parsing_err);
	}
	return (minishell);
}
