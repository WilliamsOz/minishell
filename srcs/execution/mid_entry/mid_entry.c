/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:16:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/03 12:16:58 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

t_cmd	*mid_entry(t_minishell *minishell, t_cmd *tmp_cmd, char **env)
{
	if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
	{
		// prepare_fd_builtin();
		execute_builtin(minishell, tmp_cmd);
	}
	else
		rw_inside_pipes(minishell, tmp_cmd, env);
	tmp_cmd = tmp_cmd->next;
	return (tmp_cmd);
}
