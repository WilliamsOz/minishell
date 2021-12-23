/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:12:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 17:51:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*copy_expanded_value(char *token, t_env *env, char *dest, int *p_j)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	while (tmp != NULL)
	{
		i = 0;
		if (tmp->var[i] == token[i])
			while (tmp->var[i] == token[i])
				i++;
		if (tmp->var[i++] == '=')
		{
			while (tmp->var[i] != '\0')
			{
				dest[*p_j] = tmp->var[i];
				*p_j += 1;
				i++;
			}
			return (dest);
		}
		tmp = tmp->next;
	}
	return (dest);
}
