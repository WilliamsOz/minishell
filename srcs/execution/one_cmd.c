/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:01:49 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/30 16:53:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

static void	close_fd(t_cmd *tmp_cmd)
{
	if (tmp_cmd->input != STDIN_FILENO)
		close(tmp_cmd->input);
	if (tmp_cmd->output != STDOUT_FILENO)
		close(tmp_cmd->output);
}

static void	execve_failed()
{
	strerror(errno);
	signal_handler = 127;
	exit (127);
}

void exec_one_cmd(t_minishell *m, t_cmd *tmp_cmd, char **env)
{
	pid_t	pid;
	int		status;

	signal(SIGQUIT, cmd_handlers);
	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		signal_handler = -1;
		link_child(tmp_cmd);
		execve(tmp_cmd->path, tmp_cmd->cmd, env);
		execve_failed();
	}
	else
	{
		waitpid(0, &status, 0);
		//statue value :
		// 131 = SIGQUIT
		// 2 = SIGINT
		// 32512 = UNKNOW_CMD
		PD(status)
		close_fd(tmp_cmd);
	}
}
