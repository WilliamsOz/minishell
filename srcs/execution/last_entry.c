/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:41:39 by user42            #+#    #+#             */
/*   Updated: 2022/01/02 00:52:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	execute_last_cmd(t_minishell *m, t_cmd *tmp_cmd, char **env)
{
	pid_t	pid;
	// int		status;

	// signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		dup2(tmp_cmd->previous->pipes[0], STDIN_FILENO);
		close(tmp_cmd->pipes[0]);
		close(tmp_cmd->pipes[1]);
		if (tmp_cmd->output != STDOUT_FILENO)
			dup2(tmp_cmd->output, STDOUT_FILENO);
		execve(tmp_cmd->path, tmp_cmd->cmd, env);
	}
	else
	{
		// waitpid(0, &status, WNOHANG);
		// if (WIFSIGNALED(status))
			// ICI
	}
}
