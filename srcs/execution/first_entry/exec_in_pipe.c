/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_in_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:40:16 by user42            #+#    #+#             */
/*   Updated: 2022/01/03 16:21:29 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	exec_in_pipe(t_minishell *minishell, t_cmd *tmp_cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fork_failed(minishell);
	if (pid == 0)
	{
		close(tmp_cmd->pipes[0]);
		dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
		close(tmp_cmd->pipes[1]);
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
			execute_builtin(minishell, tmp_cmd);
		else
			execve(tmp_cmd->path, tmp_cmd->cmd, minishell->tab_env);
		exit (errno);
	}
	else 
		close(tmp_cmd->pipes[1]);
}
