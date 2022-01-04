/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:13:03 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/04 21:09:55 by oozsertt         ###   ########.fr       */
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

static int	var_exist(t_env *env, char *str) // a finir
{
	char	**var_and_value = NULL;
	t_env	*tmp;
	int		i;

	var_and_value = ft_split(str, '=');
	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strcmp(var_and_value[0], tmp->var) == 1)
		{
			i = 0;
			while (var_and_value[i] != NULL)
			{
				free(var_and_value[i]);
				i++;
			}
			free(var_and_value);
			return (TRUE);
		}
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
		printf("TRUE\n");
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
