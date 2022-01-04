/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:10:32 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 10:10:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	move_to_value(char *env, int i)
{
	while (env[i] != '\0' && env[i] != '=')
		i++;
	if (env[i] == '=')
		i++;
	return (i);
}
