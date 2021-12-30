/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_cmd_from_dlk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:47:12 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/30 13:37:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd	*cpy_cmd_from_dlk(t_cmd *cmd, t_dlk_list *dlk)
{
	t_dlk_list	*tmp_dlk;
	t_cmd		*tmp_cmd;

	tmp_dlk = dlk;
	tmp_cmd = cmd;
	while (tmp_dlk != NULL)
	{
		if (tmp_dlk->cmd != NULL)
		{
			tmp_cmd->cmd = tmp_dlk->cmd;
			tmp_cmd = tmp_cmd->next;
		}
		tmp_dlk = tmp_dlk->next;
	}
	return (cmd);
}
