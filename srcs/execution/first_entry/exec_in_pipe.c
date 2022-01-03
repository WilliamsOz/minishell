/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_in_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:40:16 by user42            #+#    #+#             */
/*   Updated: 2022/01/03 12:03:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static void	link_child(t_cmd *tmp_cmd)
{
	if (tmp_cmd->input != STDIN_FILENO)
		dup2(tmp_cmd->input, STDIN_FILENO);
	if (tmp_cmd->output != STDOUT_FILENO)
		dup2(tmp_cmd->output, STDOUT_FILENO);
	else
	{
		dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
		close(tmp_cmd->pipes[1]);
	}
}

void	exec_in_pipe(t_minishell *minishell, t_cmd *tmp_cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fork_failed(minishell);
	if (pid == 0)
	{
		link_child(tmp_cmd);
		close(tmp_cmd->pipes[0]);
		execve(tmp_cmd->path, tmp_cmd->cmd, minishell->tab_env);
		exit (errno);
	}
	else 
		close(tmp_cmd->pipes[1]);
}
