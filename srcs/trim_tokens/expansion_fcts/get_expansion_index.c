/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:14:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 16:15:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	get_expanded_index(char *token, char **env, int i, int j)
{
	while (env[i] != NULL)
	{
		while (env[i][j] != '\0')
		{
			if (j == 0 && env[i][j] == token[j])
			{
				while (env[i][j] == token[j])
					j++;
				if (env[i][j] == '=')
					return (i);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}
