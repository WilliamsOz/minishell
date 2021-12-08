/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_get_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:27:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 19:03:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	__get_expanded_len__(char *token, int *ptr_i, int j, char **env)
{
	int	i;
	int	len;

	len = 0;
	i = get_expanded_index(token, env, 0, 0);
	while (env[i][j] != '=')
	{
		j++;
		*ptr_i += 1;
	}
	j++;
	while (env[i][j] != '\0')
	{
		j++;
		if (env[i][j] != '\0')
			len++;
	}
	return (len);
}

int	bc_get_len(char *token, int *ptr_i, int len, char **env)
{
	int	i;

	i = *ptr_i;
	while (token[i] != '\0' &&
		token[i] != SIMPLE_COTE && token[i] != DOUBLE_COTE)
	{
		if (token[i] == '$' &&
			existing_expand(token + i + 1, env, 0 ,0) == TRUE)
			len += __get_expanded_len__(token + i + 1, &i, 0, env);
		else
		{
			i++;
			len++;
		}
	}
	*ptr_i = i;
	return (len);
}
