/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_in_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:40:16 by user42            #+#    #+#             */
/*   Updated: 2022/01/02 15:17:15 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static void	close_fd(t_cmd *tmp_cmd)
{
	if (tmp_cmd->input != STDIN_FILENO)
		close(tmp_cmd->input);
	if (tmp_cmd->output != STDOUT_FILENO)
		close(tmp_cmd->output);
}

static void	link_child(t_cmd *tmp_cmd)
{
	if (tmp_cmd->input != STDIN_FILENO)
	{
		dup2(tmp_cmd->input, STDIN_FILENO);
		close(tmp_cmd->input);
	}
	if (tmp_cmd->output != STDOUT_FILENO)
	{
		dup2(tmp_cmd->output, STDOUT_FILENO);
		close(tmp_cmd->output);
	}
}

void	exec_in_pipe(t_minishell *minishell, t_cmd *tmp_cmd)
{
	pid_t	pid;
	// int		status;

	pid = fork();
	if (pid == -1)
		fork_failed(minishell);
	if (pid == 0)
	{
		link_child(tmp_cmd);
		close(tmp_cmd->pipes[0]);
		dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
		execve(tmp_cmd->path, tmp_cmd->cmd, minishell->tab_env);
		exit (errno);
	}
	else 
	{
		close(tmp_cmd->pipes[1]);
		close_fd(tmp_cmd);
	}
}
