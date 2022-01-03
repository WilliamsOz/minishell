/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:43:33 by user42            #+#    #+#             */
/*   Updated: 2022/01/03 12:16:59 by wiozsert         ###   ########.fr       */
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

void	prepare_fd_builtin(t_cmd *tmp_cmd)
{
	if (tmp_cmd->input == STDIN_FILENO)
		dup2(tmp_cmd->input, tmp_cmd->pipes[0]);
	if (tmp_cmd->output == STDOUT_FILENO)
		dup2(tmp_cmd->output, tmp_cmd->pipes[1]);
}

t_cmd	*first_entry(t_minishell *minishell, t_cmd *tmp_cmd, char **env)
{
	if (tmp_cmd->next == NULL)
	{
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
			execute_builtin(minishell, tmp_cmd);
		else
			exec_one_cmd(minishell, tmp_cmd, env);
	}
	else
	{
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
		{
			prepare_fd_builtin(tmp_cmd);
			execute_builtin(minishell, tmp_cmd);
		}
		else
			exec_in_pipe(minishell, tmp_cmd);
	}
	close_fd(tmp_cmd);
	tmp_cmd = tmp_cmd->next;
	return (tmp_cmd);
}
