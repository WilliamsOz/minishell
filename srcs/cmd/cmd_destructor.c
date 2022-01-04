/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_destructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:32:38 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 12:10:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd	*cmd_destructor(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	while (cmd != NULL)
	{
		i = 0;
		tmp = cmd;
		cmd = cmd->next;
		while (tmp->cmd[i] != NULL)
		{
			free(tmp->cmd[i]);
			tmp->cmd[i] = NULL;
			i++;
		}
		free(tmp->cmd[i]);
		if (tmp->path != NULL)
		{
			free(tmp->path);
			tmp->path = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
	free(cmd);
	cmd = NULL;
	return (cmd);
}

t_minishell	*tab_env_destructor(t_minishell *m)
{
	int	i;

	i = 0;
	while (m->tab_env[i] != NULL)
	{
		free(m->tab_env[i]);
		m->tab_env[i] = NULL;
		i++;
	}
	free(m->tab_env);
	m->tab_env = NULL;
	return (m);
}

t_minishell	*destroy_cmd_data(t_minishell *m)
{
	m = tab_env_destructor(m);
	m->cmd = cmd_destructor(m->cmd);
	return (m);
}
