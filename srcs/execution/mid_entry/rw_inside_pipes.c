/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rw_inside_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:15:00 by user42            #+#    #+#             */
/*   Updated: 2022/01/05 16:07:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static void	link_child(t_cmd *tmp_cmd)
{
	dup2(tmp_cmd->previous->pipes[0], STDIN_FILENO);
	close(tmp_cmd->previous->pipes[0]);
	dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
	close(tmp_cmd->pipes[1]);
}

t_minishell	*rw_inside_pipes(t_minishell *m, t_cmd *tmp_cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		link_child(tmp_cmd);
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
			execute_builtin(m, tmp_cmd);
		else
		{
			execve(tmp_cmd->path, tmp_cmd->cmd, m->tab_env);
			m = free_child(m);
		}
		m = free_child(m);
		exit (0);
	}
	else
	{
		close(tmp_cmd->previous->pipes[0]);
		close(tmp_cmd->pipes[1]);
		waitpid(0, &tmp_cmd->status, 0);
	}
	return (m);
}
