/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_needed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:14:49 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/14 12:15:13 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	expansion_needed(char *buffer, int i)
{
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '$')
			return (TRUE);
		else
			i++;
	}
	return (FALSE);
}
