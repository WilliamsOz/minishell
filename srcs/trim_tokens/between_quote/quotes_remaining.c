/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_remaining.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:05:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 17:05:47 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	quotes_remaining(char *token, int i)
{
	while (token[i] != '\0')
	{
		if (token[i] == SIMPLE_COTE || token[i] == DOUBLE_COTE)
			return (TRUE);
		else
			i++;
	}
	return (FALSE);
}
