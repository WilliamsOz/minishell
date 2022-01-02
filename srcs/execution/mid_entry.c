/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:15:00 by user42            #+#    #+#             */
/*   Updated: 2022/01/02 00:51:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	rw_inside_pipes(t_minishell *m, t_cmd *tmp_cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		dup2(tmp_cmd->previous->pipes[0], STDIN_FILENO);
		close(tmp_cmd->previous->pipes[1]);
		dup2(tmp_cmd->pipes[1], STDOUT_FILENO);
		close(tmp_cmd->pipes[0]);
		execve(tmp_cmd->path, tmp_cmd->cmd, env);
	}
	else
	{
		return ;
	}
}
