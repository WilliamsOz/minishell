/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_in_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:40:16 by user42            #+#    #+#             */
/*   Updated: 2022/01/02 00:50:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	exec_in_pipe(t_minishell *minishell, t_cmd *cmd)
{
	pid_t	pid;
	// int		status;

	pid = fork();
	if (pid == -1)
		fork_failed(minishell);
	if (pid == 0)
	{
		close(cmd->pipes[0]);
		dup2(cmd->pipes[1], STDOUT_FILENO);
		// close(cmd->pipes[1]);
		execve(cmd->path, cmd->cmd, minishell->tab_env);
		exit (errno);
	}
	else 
	{
		close(cmd->pipes[1]);
		// waitpid(0, &status, WUNTRACED);
		// if (status == TRUE)
		// 	ICI	
	}
}
