/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:45:08 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/29 19:30:28 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd	*memset_pipes(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		tmp->pipes[0] = -1;
		tmp->pipes[1] = -1;
		tmp = tmp->next;
	}
	return (cmd);
}

t_minishell	*open_pipes(t_minishell *m)
{
	t_cmd	*tmp;

	tmp = m->cmd;
	while (tmp != NULL)
	{
		tmp = tmp->next;
	}
	return (m);
}

t_cmd	*get_previous(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*next;

	tmp = cmd;
	if (tmp != NULL)
		tmp->previous = NULL;
	while (tmp != NULL)
	{
		PS(tmp->cmd[0])
		next = tmp->next;
		next->previous = tmp;
		tmp = tmp->next;
	}
	return (cmd);
}

t_minishell	*get_cmd(t_minishell *m)
{
	m->cmd = init_cmd(m, m->d_lk);
	m->cmd = memset_pipes(m->cmd);
	m = open_pipes(m);
	m = performs_redirection(m);
	m->d_lk = memset_dlk_cmd(m->d_lk);
	m->d_lk = get_dlk_cmd(m, m->d_lk);
	m->cmd = cpy_cmd_from_dlk(m->cmd, m->d_lk);
	m->cmd = get_previous(m->cmd);
	t_cmd	*cmd = m->cmd;

	while (cmd != NULL)
	{
		if (cmd->previous != NULL)
			PS(cmd->previous->cmd[0])
		cmd = cmd->next;
	}
	ex
	m->cmd = find_and_get_path_cmd(m, m->cmd, m->env);
	return (m);
}
