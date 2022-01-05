/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:01:49 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 13:16:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

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

static void	interpret_status(t_cmd *cmd, int status, char **env)
{
	if (status == 512 && path_removed(env) == TRUE)
		no_file_or_directory(cmd->cmd[0]);
	else if (status == 131)
		print_core_dumped();
	else if (status == 512 && ft_strcmp(cmd->cmd[0], "ls") == TRUE)
		g_signal_handler = 2;
	else if (status == 512 || status == 3584)
		command_not_found(cmd->cmd[0]);
	else if (status == 256)
		g_signal_handler = 1;
	else if (status == 0)
		g_signal_handler = 0;
	else if (status == 2)
		write(1, "\n", 1);
}

void	exec_one_cmd(t_minishell *m, t_cmd *tmp_cmd, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		g_signal_handler = -1;
		link_child(tmp_cmd);
		execve(tmp_cmd->path, tmp_cmd->cmd, env);
		m = free_child(m);
		exit (errno);
	}
	else
	{
		waitpid(0, &status, 0);
		interpret_status(tmp_cmd, status, env);
	}
}
