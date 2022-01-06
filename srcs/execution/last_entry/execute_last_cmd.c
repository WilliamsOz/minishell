/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_last_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:41:39 by user42            #+#    #+#             */
/*   Updated: 2022/01/06 15:30:15 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

t_minishell	*execute_last_cmd(t_minishell *m, t_cmd *tmp_cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		dup2(tmp_cmd->previous->pipes[0], STDIN_FILENO);
		close(tmp_cmd->previous->pipes[0]);
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
			execute_builtin(m, tmp_cmd);
		else
			execve(tmp_cmd->path, tmp_cmd->cmd, m->tab_env);
		m = free_child(m);
		exit (errno);
	}
	else
	{
		close(tmp_cmd->previous->pipes[1]);
		close(tmp_cmd->previous->pipes[0]);
		waitpid(0, &tmp_cmd->status, 0);
	}
	return (m);
}
