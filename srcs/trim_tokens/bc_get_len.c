/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_get_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:27:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 17:30:41 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	__existing_expand__(char *token, char **env, int i, int j)
{
	while (env[i] != NULL)
	{
		while (env[i][j] != '\0')
		{
			if (env[i][j] == token[j])
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

static int	__expansion_found__(char *env, char *token)
{
	int	i;

	i = 0;
	while (env[i] == token[i] && env[i] != '=')
		i++;
	if (env[i] == '=')
		return (TRUE);
	return (FALSE);
}

static int	__get_expansion_lenght__(char *env, int **ptr_i)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	**ptr_i += 1;
	while (env[i] != '=')
	{
		i++;
		**ptr_i += 1;
	}
	i++;
	while (env[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	__get_expanded_len__(char *token, int *ptr_i, int j, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (env[i] != NULL)
	{
		while (env[i][j] != '\0')
		{
			if (env[i][j] == token[j])
			{
				if (__expansion_found__(env[i], token) == TRUE)
				{
					len = __get_expansion_lenght__(env[i], &ptr_i);
					return (len);
				}
			}
			j++;
		}
		j = 0;
		i++;
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
			__existing_expand__(token + i + 1, env, 0 ,0) == TRUE)
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
