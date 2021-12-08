/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:09:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 17:25:19 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	existing_expand(char *token, char **env, int i, int j)
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

static int	expansion_found(char *env, char *token)
{
	int	i;

	i = 0;
	while (env[i] == token[i] && env[i] != '=')
		i++;
	if (env[i] == '=')
		return (TRUE);
	return (FALSE);
}

static int	get_expansion_lenght(char *env, int **ptr_i)
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

static int	get_expanded_len(char *token, int *ptr_i, int j, char **env)
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
				if (expansion_found(env[i], token) == TRUE)
				{
					len = get_expansion_lenght(env[i], &ptr_i);
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

static int	get_len(char *token, int *ptr_i, int len, char **env)
{
	int	i;

	i = *ptr_i;
	while (token[i] != '\0' &&
		token[i] != SIMPLE_COTE && token[i] != DOUBLE_COTE)
	{
		if (token[i] == '$' &&
			existing_expand(token + i + 1, env, 0 ,0) == TRUE)
			len += get_expanded_len(token + i + 1, &i, 0, env);
		else
		{
			i++;
			len++;
		}
	}
	*ptr_i = i;
	return (len);
}

char		*before_quote(t_trim *trim, char *token, int *ptr_i, char **env)
{
	int	len;
	int	i;

	i = *ptr_i;
	len = get_len(token, &i, 0, env);
	
	*ptr_i = i;
	return (trim->before_quote);
}
