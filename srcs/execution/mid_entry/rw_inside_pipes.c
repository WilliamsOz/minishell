/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rw_inside_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:15:00 by user42            #+#    #+#             */
/*   Updated: 2022/01/04 20:16:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	rw_inside_pipes(t_minishell *minishell, t_cmd *tmp_cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fork_failed(minishell);
	if (pid == 0)
	{
		dup2(tmp_cmd->previous->pipes[0], STDIN_FILENO);
		close(tmp_cmd->previous->pipes[0]);
		dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
		close(tmp_cmd->pipes[1]);
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
			execute_builtin(minishell, tmp_cmd);
		else
			execve(tmp_cmd->path, tmp_cmd->cmd, env);
		minishell = free_child(minishell);
		exit (errno);
	}
	else
	{
		close(tmp_cmd->previous->pipes[0]);
		close(tmp_cmd->pipes[1]);
	}
}
