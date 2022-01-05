/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:17:33 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 15:53:14 by wiozsert         ###   ########.fr       */
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

t_cmd	*last_entry(t_minishell *minishell, t_cmd *tmp_cmd)
{
	if (tmp_cmd == NULL)
		return (tmp_cmd);
	execute_last_cmd(minishell, tmp_cmd);
	close_fd(tmp_cmd);
	tmp_cmd = tmp_cmd->next;
	return (tmp_cmd);
}
