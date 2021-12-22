/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:30:39 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/22 20:07:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_index	get_index(int i)
{
	t_index index;

	index.i = i;
	index.j = 0;
	return (index);
}

static char	*__get_sq__(char *token, char *tmp, int *ptr_i, int *ptr_j)
{
	int	i;
	int	j;

	*ptr_i += 1;
	i = *ptr_i;
	j = *ptr_j;
	while (token[i] != SIMPLE_COTE)
	{
		tmp[j] = token[i];
		i++;
		j++;
	}
	i++;
	*ptr_i = i;
	*ptr_j = j;
	return (tmp);
}

static char	*__get_dq__(char *token, char *tmp, t_index *index, char **env)
{
	index->i += 1;
	while (token[index->i] != DOUBLE_COTE)
	{
		if (token[index->i] == '$' &&
			dc_existing_expand(token + index->i + 1, env, 0, 0) == TRUE)
		{
			tmp = copy_expanded_value(token + index->i + 1, env, tmp,
				&index->j);
			index->i += get_end_of_expansion(token + index->i + 1, env, 0, 0);
		}
		else if (token[index->i] == '$' && token[index->i + 1] == '?')
			tmp = cpy_status(tmp, signal_handler, &index->i, &index->j);
		else if (token[index->i] == '$')
			index->i = skip_unk_exp(token, index->i);
		else
		{
			tmp[index->j] = token[index->i];
			index->i += 1;
			index->j += 1;
		}
	}
	index->i += 1;
	return (tmp);
}

char	*get_trimed_token(char *token, char *tmp, char **env, int *ptr_i)
{
	t_index	index;

	index = get_index(*ptr_i);
	while (token[index.i] != '\0')
	{
		if (token[index.i] == SIMPLE_COTE)
			tmp = __get_sq__(token, tmp, &index.i, &index.j);
		else if (token[index.i] == DOUBLE_COTE)
			tmp = __get_dq__(token, tmp, &index, env);
		else if (token[index.i] == '$' &&
			existing_expand(token + index.i + 1, env, 0, 0) == TRUE)
		{
			tmp = copy_expanded_value(token + index.i + 1, env, tmp,
				&index.j);
			index.i += get_end_of_expansion(token + index.i + 1, env, 0, 0);
		}
		else if (token[index.i] == '$' && token[index.i + 1] == '?')
			cpy_status(tmp, signal_handler, &index.i, &index.j);
		else if (token[index.i] == '$')
			index.i = skip_unk_exp(token, index.i);
		else
			tmp[index.j++] = token[index.i++];
	}
	*ptr_i = index.i;
	return (tmp);
}
