/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bw_token_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:00:10 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/11 15:37:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int inside_sc(char *token, int *ptr_i, int len)
{
	int	i;

	i = *ptr_i + 1;
	while (token[i] != SIMPLE_COTE)
	{
		if (token[i] != SIMPLE_COTE)
			len++;
		i++;
	}
	i++;
	*ptr_i = i;
	return (len);
}

static int	inside_dc(char *token, int *ptr_i, int len, char **env)
{
	int	i;

	i = *ptr_i + 1;
	while (token[i] != DOUBLE_COTE)
	{
		if (token[i] == '$')
		{
			if (existing_expand(token + i + 1, env, 0, 0) == TRUE)
				len += get_expanded_len(token + i + 1, &i, 0, env);
			else
			{
				i++;
				len++;
			}
		}
		else
		{
			i++;
			len++;
		}
	}
	*ptr_i = i + 1;
	return (len);
}

static void	inc_i_and_len(int *ptr_i, int *ptr_len)
{
	*ptr_i += 1;
	*ptr_len += 1;
}

int	get_between_len(char *token, char **env, int i, int len)
{
	while (token[i] != '\0' && quotes_remaining(token + i, 0) == TRUE)
	{
		if (token[i] == SIMPLE_COTE)
			len = inside_sc(token, &i, len);
		else if (token[i] == DOUBLE_COTE)
			len = inside_dc(token, &i, len, env);
		else if (token[i] == '$')
		{
			if (existing_expand(token + i + 1, env, 0, 0) == TRUE)
				len += get_expanded_len(token + i + 1, &i, 0, env);
			else
				inc_i_and_len(&i, &len);
		}
		else
				inc_i_and_len(&i, &len);
	}
	PD(len)
	return (len);
}
