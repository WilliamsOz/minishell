/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:15:00 by user42            #+#    #+#             */
/*   Updated: 2022/01/03 12:14:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static void	link_child(t_cmd *tmp_cmd)
{
	if (tmp_cmd->input != STDIN_FILENO)
	{
		dup2(tmp_cmd->input, STDIN_FILENO);
		close(tmp_cmd->input);
		close(tmp_cmd->previous->pipes[0]);
	}
	else
	{
		dup2(tmp_cmd->previous->pipes[0], STDIN_FILENO);
		close(tmp_cmd->previous->pipes[0]);
	}
	if (tmp_cmd->output != STDOUT_FILENO)
	{
		dup2(tmp_cmd->output, STDOUT_FILENO);
		close(tmp_cmd->output);
		close(tmp_cmd->pipes[1]);
	}
	else
	{
		dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
		close(tmp_cmd->pipes[1]);
	}
}

static void	close_fd(t_cmd *tmp_cmd)
{
	if (tmp_cmd->input != STDIN_FILENO)
		close(tmp_cmd->input);
	if (tmp_cmd->output != STDOUT_FILENO)
		close(tmp_cmd->output);
}

void	rw_inside_pipes(t_minishell *m, t_cmd *tmp_cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		link_child(tmp_cmd);
		execve(tmp_cmd->path, tmp_cmd->cmd, env);
	}
	else
	{
		close(tmp_cmd->previous->pipes[0]);
		close(tmp_cmd->pipes[1]);
		close_fd(tmp_cmd);
	}
}
