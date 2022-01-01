/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:43:12 by user42            #+#    #+#             */
/*   Updated: 2022/01/01 20:14:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	env_destructor(t_env *env)
{
	t_env	*tmp;

	if (env == NULL)
	{
		free(env->var);
		free(env);
	}
	else
	{
		while (env != NULL)
		{
			tmp = env;
			env = env->next;
			free(tmp->var);
			free(tmp);
		}	
	}
}

t_env	*env_creator(t_minishell *m, char **env)
{
	t_env	*root;

	m->env = create_root(m, &root, env);
	return (root);
}
