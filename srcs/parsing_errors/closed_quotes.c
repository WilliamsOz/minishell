/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:58:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 14:39:32 by user42           ###   ########.fr       */
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
	t_parsing_err	*parsing_err;

	parsing_err = parsing_err_creator();
	parsing_err->simple_cote = 0;
	parsing_err->double_cote = 0;
	while (line[i] != '\0')
	{
		if (line[i] == SIMPLE_COTE || line[i] == DOUBLE_COTE)
		{
			i = __get_end__(line, i, &parsing_err->simple_cote,
				&parsing_err->double_cote);
		}
		else
			i++;
	}
	if (parsing_err->simple_cote == 1 || parsing_err->double_cote == 1)
	{
		ft_putstr_fd("Unclosed Quotes\n", 2);
		add_history(minishell->line);
		minishell->line = free_line(minishell->line);
	}
	return (minishell);
}
