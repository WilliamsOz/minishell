/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:58:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 15:04:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	quotes_closed(t_parsing_err *parsing_err, int i, char *line)
{
	parsing_err->simple_cote = 0;
	parsing_err->double_cote = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 39)
			parsing_err->simple_cote++;
		else if (line[i] == 34)
			parsing_err->double_cote++;
		i++;
	}
	if (parsing_err->simple_cote % 2 != 0 ||
		parsing_err->double_cote % 2 != 0)
		return (FALSE);
	return (TRUE);
}