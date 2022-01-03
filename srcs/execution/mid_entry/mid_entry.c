/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:16:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/03 16:11:15 by wiozsert         ###   ########.fr       */
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

t_cmd	*mid_entry(t_minishell *minishell, t_cmd *tmp_cmd, char **env)
{
	rw_inside_pipes(minishell, tmp_cmd, env);
	close_fd(tmp_cmd);
	tmp_cmd = tmp_cmd->next;
	return (tmp_cmd);
}
