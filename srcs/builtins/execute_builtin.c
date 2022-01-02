/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:32:44 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 16:39:37 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	execute_builtin(t_minishell *m, t_cmd *tmp_cmd)
{
	if (ft_strcmp("cd", tmp_cmd->cmd[0]) == TRUE)
		cd_builtin(tmp_cmd, &m->env);
	if (ft_strcmp("echo", tmp_cmd->cmd[0]) == TRUE)
		echo_builtin(tmp_cmd);
	if (ft_strcmp("env", tmp_cmd->cmd[0]) == TRUE)
		env_builtin(m->env);
	if (ft_strcmp("exit", tmp_cmd->cmd[0]) == TRUE)
		exit_builtin(tmp_cmd);
	if (ft_strcmp("export", tmp_cmd->cmd[0]) == TRUE)
		export_builtin(tmp_cmd, &m->env);
	if (ft_strcmp("pwd", tmp_cmd->cmd[0]) == TRUE)
		pwd_builtin(tmp_cmd, m->env);
	if (ft_strcmp("unset", tmp_cmd->cmd[0]) == TRUE)
		unset_builtin(tmp_cmd, &m->env);
}
