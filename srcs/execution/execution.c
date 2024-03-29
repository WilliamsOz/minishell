/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:09:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/06 16:19:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	print_status(t_cmd *cmd, int status, char **env)
{
	if ((status == 512 && path_removed(env) == TRUE)
		|| (status == 512 && errno == 20 && cmd->cmd[0][0] == '/'
		&& access(cmd->path, F_OK | X_OK) == -1))
		no_file_or_directory(cmd->cmd[0]);
	else if (status == 131)
		print_core_dumped();
	else if ((status == 512 && cmd->cmd[0][0] != '/'
		&& access(cmd->path, F_OK | X_OK) == -1)
		|| status == 3584 || status == 3328
		|| (status == 512 && access(cmd->path, F_OK | X_OK) == -1))
		command_not_found(cmd->cmd[0]);
	else if (status == 256)
		g_signal_handler = 1;
	else if (status == 0)
		g_signal_handler = 0;
	else if (status == 2)
		write(1, "\n", 1);
	if (status == 512)
		g_signal_handler = 2;
}

static void	interpret_status(t_cmd *cmd, char **env)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		print_status(tmp, tmp->status, env);
		tmp = tmp->next;
	}
}

void	execution(t_minishell *minishell, char **env)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = minishell->cmd;
	if (tmp_cmd->next == NULL)
	{
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
			execute_builtin(minishell, tmp_cmd);
		else
			exec_one_cmd(minishell, tmp_cmd, env);
		return ;
	}
	tmp_cmd = first_entry(minishell, tmp_cmd);
	while (tmp_cmd != NULL && tmp_cmd->next != NULL)
		tmp_cmd = mid_entry(minishell, tmp_cmd);
	tmp_cmd = last_entry(minishell, tmp_cmd);
	interpret_status(minishell->cmd, env);
}
