/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:02:38 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 17:03:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*bq_get_final_token(char *token, char *tmp, char **env, int i)
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
