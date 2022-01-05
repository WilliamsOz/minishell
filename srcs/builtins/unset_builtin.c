/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:02:20 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 13:23:48 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// si arg correspond a aucune variable d'env, ne fais rien

#include "../../inc/minishell.h"

static int	is_var(char *env_var, char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] != env_var[i] || env_var[i] == '\0')
			return (FALSE);
		i++;
	}
	if (arg[i] == '\0' && env_var[i] != '\0'
		&& env_var[i] == '=')
		return (TRUE);
	else
		return (FALSE);
}

static void	unset_var(t_env *previous, t_env *node, t_env *next)
{
	free(node->var);
	previous->next = next;
	free(node);
}

void	unset_builtin(t_cmd *cmd, t_env **env)
{
	t_env	*tmp;
	t_env	*previous;

	if (cmd->cmd[1] == NULL)
		return ;
	tmp = *env;
	while (tmp != NULL)
	{
		if (is_var(tmp->var, cmd->cmd[1]) == 1)
		{
			unset_var(previous, tmp, tmp->next);
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}	
}
