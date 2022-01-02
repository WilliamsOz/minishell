/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:49:32 by user42            #+#    #+#             */
/*   Updated: 2022/01/02 01:02:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	execute_builtin(t_minishell *minishell, t_cmd *cmd)
{
	// if (ft_strcmp("echo", cmd->cmd[0]) == TRUE)
		// echo_builtin();
	// else if (ft_strcmp("cd", cmd->cmd[0]) == TRUE)
		// cd_builtin();
	if (ft_strcmp("pwd", cmd->cmd[0]) == TRUE)
		pwd_builtin(minishell->cmd, minishell->env);
	// else if (ft_strcmp("export", cmd->cmd[0]) == TRUE)
	// 	export_builtin();
	// else if (ft_strcmp("unset", cmd->cmd[0]) == TRUE)
	// 	unset_builtin();
	// else if (ft_strcmp("env", cmd->cmd[0]) == TRUE)
	// 	env_builtin();
	// else if (ft_strcmp("exit", cmd->cmd[0]) == TRUE)
	// 	exit_builtin();
}
