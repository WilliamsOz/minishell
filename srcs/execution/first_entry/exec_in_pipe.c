/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_in_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:40:16 by user42            #+#    #+#             */
/*   Updated: 2022/01/04 20:16:40 by user42           ###   ########.fr       */
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
		dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
		close(tmp_cmd->pipes[1]);
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
			execute_builtin(minishell, tmp_cmd);
		else
			execve(tmp_cmd->path, tmp_cmd->cmd, minishell->tab_env);
		minishell = free_child(minishell);
		exit (errno);
	}
	else
		close(tmp_cmd->pipes[1]);
}
