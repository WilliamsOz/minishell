/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_final_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:02:38 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 18:57:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*copy_expanded_value(char *token, char **env, char *tmp, int *p_j)
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

char	*bc_get_final_token(char *token, char *tmp, char **env, int i)
{
	int	j;

	j = 0;
	while (token[i] != '\0')
	{
		if (token[i] == '$' && existing_expand(token + i + 1, env, 0,
			0) == TRUE)
		{
			tmp = copy_expanded_value(token + i + 1, env, tmp, &j);
			i += get_end_of_expansion(token + i + 1, env, 0, 0);
		}
		else
		{
			tmp[j] = token[i];
			j++;
			i++;
		}
	}
	return (tmp);
}
