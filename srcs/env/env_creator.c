/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:47:37 by user42            #+#    #+#             */
/*   Updated: 2021/12/23 18:45:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_env	*get_last(t_env *root)
{
	t_env	*tmp;

	tmp = root;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

static void		new_node_malloc_failed(t_minishell *m, t_env *root)
{
	t_env	*tmp;

	free(root->var);
	while (root != NULL)
	{
		tmp = root;
		root = root->next;
		free(tmp);
	}
	m = destroy_all_data(m);
}

static t_env	*get_node(t_minishell *m, char **env, int i)
{
	t_env	*keep;
	t_env	*new;

	while (env[i] != NULL)
	{
		new = (t_env *)malloc(sizeof(t_env));
		new->var = NULL;
		if (new == NULL)
			new_node_malloc_failed(m, m->env);
		new->next = NULL;
		if (i == 0)
			m->env->next = new;
		else
		{
			keep = get_last(m->env);
			keep->next = new;
		}
		i++;
	}
	return (m->env);
}

static void		mall_root_var_failed(t_minishell *m)
{
	strerror(errno);
	free(m->env);
	m = destroy_all_data(m);
	exit (EXIT_FAILURE);
}

t_env	*create_root(t_minishell *m, t_env **root, char **env)
{
	*root = (t_env *)malloc(sizeof(t_env));
	(*root)->next = NULL;
	if (root == NULL)
	{
		strerror(errno);
		m = destroy_all_data(m);
		exit (EXIT_FAILURE);
	}
	if (env[0] == NULL)
	{
		(*root)->var = (char*)malloc(sizeof(char));
		if ((*root)->var == NULL)
			mall_root_var_failed(m);
	}
	else
	{
		m->env = *root;
		*root = get_node(m, env, 1);
	}
	return (*root);
}