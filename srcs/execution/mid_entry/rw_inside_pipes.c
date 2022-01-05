/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rw_inside_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:15:00 by user42            #+#    #+#             */
/*   Updated: 2022/01/05 15:02:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static void	interpret_status(t_cmd *cmd, int status, char **env)
{
	if (status == 512 && path_removed(env) == TRUE)
		no_file_or_directory(cmd->cmd[0]);
	if (status == 131)
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

static void	link_child(t_cmd *tmp_cmd)
{
	dup2(tmp_cmd->previous->pipes[0], STDIN_FILENO);
	close(tmp_cmd->previous->pipes[0]);
	dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
	close(tmp_cmd->pipes[1]);
}

void	rw_inside_pipes(t_minishell *minishell, t_cmd *tmp_cmd, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		fork_failed(minishell);
	if (pid == 0)
	{
		link_child(tmp_cmd);
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
		waitpid(0, &status, 0);
		interpret_status(tmp_cmd, status, env);
	}
}
