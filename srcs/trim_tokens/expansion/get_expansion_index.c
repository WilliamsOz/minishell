/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:14:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 16:25:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	get_expanded_index(char *token, t_env *env, int i)
{
	while (env != NULL)
	{
		if (i == 0 && env->var[i] == token[i])
			while (env->var[i] == token[i])
				i++;
		if (env->var[i] == '=')
			return (i);
		env = env->next;
	}
	return (i);
}
