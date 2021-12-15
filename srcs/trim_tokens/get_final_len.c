/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:05:39 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/15 12:13:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
				i = skip_unk_exp(token, i);
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

int	get_final_len(char *token, char **env, int i, int len)
{
	while (token[i] != '\0')
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
				i = skip_unk_exp(token, i);
		}
		else
				inc_i_and_len(&i, &len);
	}
	return (len);
}
