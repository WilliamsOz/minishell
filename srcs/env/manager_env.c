/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:43:12 by user42            #+#    #+#             */
/*   Updated: 2022/01/02 18:17:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env	*env_destructor(t_env *env)
{
	t_env	*tmp;

	if (env == NULL)
	{
		free(env->var);
		env->var = NULL;
		free(env);
		env = NULL;
	}
	else
	{
		while (env != NULL)
		{
			tmp = env;
			env = env->next;
			free(tmp->var);
			tmp->var = NULL;
			free(tmp);
			tmp  = NULL;
		}	
	}
	return (env);
}

t_env	*env_creator(t_minishell *m, char **env)
{
	t_env	*root;

	m->env = create_root(m, &root, env);
	return (root);
}
