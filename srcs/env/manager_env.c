/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:43:12 by user42            #+#    #+#             */
/*   Updated: 2021/12/23 18:45:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	env_destructor(t_env *env)
{
	t_env	*tmp;

	while (env != NULL)
	{
		tmp = env;
		env = env->next;
		free(tmp->var);
		free(tmp);
	}
}

t_env	*env_creator(t_minishell *m, char **env)
{
	t_env	*root;

	m->env = create_root(m, &root, env);
	root = create_var(m, env, 0, 0);
	return (root);
}