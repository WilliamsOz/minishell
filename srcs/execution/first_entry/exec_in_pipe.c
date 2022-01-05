/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_in_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:40:16 by user42            #+#    #+#             */
/*   Updated: 2022/01/05 15:51:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

t_minishell	*exec_in_pipe(t_minishell *m, t_cmd *tmp_cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
		close(tmp_cmd->pipes[1]);
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
			execute_builtin(m, tmp_cmd);
		else
		{
			execve(tmp_cmd->path, tmp_cmd->cmd, m->tab_env);
			m = free_child(m);
		}
		exit (0);
	}
	else
	{
		close(tmp_cmd->pipes[1]);
		waitpid(0, &tmp_cmd->status, 0);
	}
	return (m);
}
