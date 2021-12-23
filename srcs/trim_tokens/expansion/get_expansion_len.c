/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:10:34 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 17:47:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	get_key(char *key, int i)
{
	int	len;

	len = 0;
	i += 1;
	while (key[i] != '\0')
	{
		i += 1;
		len++;
	}
	return (len);
}

int	get_expanded_len(char *token, int *ptr_i, int i, t_env *env)
{
	t_env	*tmp;
	int		len;

	*ptr_i += 1;
	tmp = env;
	while (tmp != NULL)
	{
		if (token[i] == tmp->var[i])
		{
			while (token[i] != '\0' && env->var[i] != '\0'
				&& token[i] == tmp->var[i])
				i++;
			if (tmp->var[i] == '=')
			{
				*ptr_i += i;
				len = get_key(tmp->var, i);
				return (len);
			}
			else
				i = 0;
		}
		tmp = tmp->next;
	}
	return (i);
}
