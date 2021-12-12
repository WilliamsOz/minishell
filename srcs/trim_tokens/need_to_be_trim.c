/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_to_be_trim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:40:23 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/11 17:09:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	need_to_be_trim(char *token, int i)
{
	while (token[i] != '\0')
	{
		if (token[i] == SIMPLE_COTE || token[i] == DOUBLE_COTE ||
			token[i] == '$')
		return (TRUE);
		i++;
	}
	return (FALSE);
}