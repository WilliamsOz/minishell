/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_remaining.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:05:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/10 18:59:52 by user42           ###   ########.fr       */
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
