/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:05:17 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 19:02:29 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int		exit_call_check(char *line, char *exit, int i, int j)
{
	while (line[i] != '\0' && (line[i] == 34 || line[i] == 39))
		i++;
	if (line[i] == '\0' || line[i] != exit[j])
		return (FALSE);
	while (line[i] != '\0' && exit[j] != '\0' && line[i] == exit[j])
	{
		i++;
		j++;
	}
	while (line[i] != '\0' && (line[i] == 34 || line[i] == 39))
		i++;
	if (line[i] == '\0')
		return (TRUE);
	return (FALSE);
}
