/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:02:20 by oozsertt          #+#    #+#             */
/*   Updated: 2021/12/30 17:41:57 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// si arg correspond a aucune variable d'env, ne fais rien

#include "../../inc/minishell.h"

static int	find_pwd(char *var, char *pwd_header)
{
	int	i;

	i = 0;
	while (pwd_header[i] != '\0')
	{
		if (var[i] != pwd_header[i] && var[i] != '\0')
			return (FALSE);
		i++;
	}
	if (pwd_header[i] == '\0')
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
		if (find_pwd(tmp->var, cmd->cmd[1]) == 1)
		{
			unset_var(previous, tmp, tmp->next);
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}	
}
