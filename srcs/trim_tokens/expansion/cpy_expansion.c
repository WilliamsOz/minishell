/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:12:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/22 20:07:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*copy_expanded_value(char *token, char **env, char *tmp, int *p_j)
{
	int	i;
	int	j;
	int	cpy;

	i = get_expanded_index(token, env, 0, 0);
	cpy = 0;
	j = *p_j;
	while (env[i][cpy] != '=')
		cpy++;
	cpy++;
	while (env[i][cpy] != '\0')
	{
		tmp[j] = env[i][cpy];
		j++;
		cpy++;
	}
	*p_j = j;
	return (tmp);
}
