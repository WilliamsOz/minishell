/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bq_token_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:27:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 17:04:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	bq_get_len(char *token, int *ptr_i, int len, char **env)
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
