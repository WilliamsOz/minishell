/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:32:44 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 16:35:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	execute_builtin(t_minishell *m, t_cmd *tmp_cmd)
{
	if (ft_strcmp("cd", str) == TRUE)
		cd_builtin(tmp_cmd, m->env);
	if (ft_strcmp("echo", str) == TRUE)
		echo_builtin(tmp_cmd);
	if (ft_strcmp("env", str) == TRUE)
		env_builtin(m->env);
	if (ft_strcmp("exit", str) == TRUE)
		exit_builtin(tmp_cmd);
	if (ft_strcmp("export", str) == TRUE)
		export_builtin(tmp_cmd, m->env);
	if (ft_strcmp("pwd", str) == TRUE)
		pwd_builtin(tmp_cmd, m->env);
	if (ft_strcmp("unset", str) == TRUE)
		unset_builtin(tmp_cmd, m->env);
}
