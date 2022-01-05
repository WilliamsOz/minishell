/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:43:33 by user42            #+#    #+#             */
/*   Updated: 2022/01/05 17:13:55 by wiozsert         ###   ########.fr       */
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

t_cmd	*first_entry(t_minishell *minishell, t_cmd *tmp_cmd)
{
	minishell = exec_in_pipe(minishell, tmp_cmd);
	close_fd(tmp_cmd);
	tmp_cmd = tmp_cmd->next;
	return (tmp_cmd);
}
