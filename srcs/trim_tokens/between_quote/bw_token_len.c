/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bw_token_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:00:10 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 17:01:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	__expansion_needed__(int *ptr_i, int do_expansion, int ind)
{
	if (ind == 1)
		do_expansion = 1;
	else if (ind == 0)
		do_expansion = 0;
	*ptr_i += 1;
	return (do_expansion);
}

int	get_between_len(char *token, char **env, int do_expansion, int i)
{
	int	len;

	len = 0;
	while (token[i] != '\0' && quotes_remaining(token + i, 0) == TRUE)
	{
		if (do_expansion == 0 && token[i] == DOUBLE_COTE)
			do_expansion = __expansion_needed__(&i, do_expansion, 1);
		if (token[i] == '$' && do_expansion == 1
			&& existing_expand(token + i + 1, env, 0, 0) == TRUE)
			len += get_expanded_len(token + i + 1, &i, 0, env);
		else
		{
			if (do_expansion == 1 && token[i] == DOUBLE_COTE)
				__expansion_needed__(&i, do_expansion, 0);
			else
			{
				if (!(do_expansion == 1 && token[i] == DOUBLE_COTE))
					len++;
				i++;
			}
		}
	}
	return (len);
}
