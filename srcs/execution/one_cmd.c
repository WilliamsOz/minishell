/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:01:49 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 15:16:48 by wiozsert         ###   ########.fr       */
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

static void	interpret_status(char *cmd, int status)
{
	if (status == 131)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		signal_handler = 131;
	}
	else if (status == 512)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		signal_handler = 127;
	}
	else if (status == 256)
		signal_handler = 1;
	else if (status == 0)
		signal_handler = 0;
	else if (status == 2)
		write(1, "\n", 1);
}

void exec_one_cmd(t_minishell *m, t_cmd *tmp_cmd, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		signal_handler = -1;
		link_child(tmp_cmd);
		execve(tmp_cmd->path, tmp_cmd->cmd, env);
		exit (errno);
	}
	else
	{
		waitpid(0, &status, 0);
		interpret_status(tmp_cmd->cmd[0], status);
		close_fd(tmp_cmd);
	}
}
