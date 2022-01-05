/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:13:03 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 11:48:57 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	check_var(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (-1);
}

static void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	replace_env_var(t_env *var_node, char *var)
{
	char	*new_var;

	new_var = NULL;
	new_var = ft_strdup(var);
	free(var_node->var);
	var_node->var = new_var;
}

static int	var_exist(t_env *env, char *str)
{
	char	**var_and_value;
	char	**env_var;
	t_env	*tmp;

	env_var = NULL;
	var_and_value = NULL;
	var_and_value = ft_split(str, '=');
	tmp = env;
	while (tmp != NULL)
	{
		env_var = ft_split(tmp->var, '=');
		if (ft_strcmp(var_and_value[0], env_var[0]) == 1)
		{
			replace_env_var(tmp, str);
			free_strs(env_var);
			free_strs(var_and_value);
			return (TRUE);
		}
		free_strs(env_var);
		tmp = tmp->next;
	}
	return (FALSE);
}

void	export_builtin(t_cmd *cmd, t_env **env)
{
	t_env	*last_node;
	t_env	*new_node;

	if (cmd->cmd[1] == NULL)
		return ;
	if (check_var(cmd->cmd[1]) == -1)
		return ;
	if (var_exist(*env, cmd->cmd[1]) == TRUE)
		return ;
	last_node = *env;
	while (last_node->next != NULL)
		last_node = last_node->next;
	new_node = (t_env *)malloc(sizeof(t_env));
	if (new_node == NULL)
		return ;
	new_node->var = ft_strdup(cmd->cmd[1]);
	if (new_node->var == NULL)
		return ;
	last_node->next = new_node;
	new_node->next = NULL;
}
