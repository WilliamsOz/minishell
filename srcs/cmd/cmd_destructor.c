/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_destructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:32:38 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 17:24:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_cmd	*free_cmd_path(t_cmd *tmp, char *cmd)
{
	if (tmp->path != cmd)
		free(tmp->path);
	tmp->path = NULL;
	return (tmp);
}

static t_cmd	*free_cmd(t_cmd *tmp, int i)
{
	while (tmp->cmd[i] != NULL)
	{
		free(tmp->cmd[i]);
		tmp->cmd[i] = NULL;
		i++;
	}
	free(tmp->cmd[i]);
	tmp->cmd[i] = NULL;
	free(tmp->cmd);
	tmp->cmd = NULL;
	free(tmp);
	tmp = NULL;
	return (tmp);
}

t_cmd	*cmd_destructor(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd != NULL)
	{
		tmp = cmd;
		cmd = cmd->next;
		if (tmp->path != NULL)
			tmp = free_cmd_path(tmp, tmp->cmd[0]);
		tmp = free_cmd(tmp, 0);
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
