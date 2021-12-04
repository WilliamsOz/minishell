/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_a_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:48:47 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/04 16:49:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_it_a_quote(char c)
{
	if (c == SIMPLE_COTE || c == DOUBLE_COTE)
		return (1);
	return (0);
}
