/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing_exansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:15:42 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 16:37:15 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	existing_expand(char *token, char **env, int i, int j)
{
	while (env[i] != NULL)
	{
		while (env[i][j] != '\0')
		{
			if (j == 0 && env[i][j] == token[j])
			{
				while (env[i][j] == token[j] && env[i][j] != '=')
					j++;
				if (env[i][j] == '=')
					return (TRUE);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (FALSE);
}
