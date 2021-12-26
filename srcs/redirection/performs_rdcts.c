/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performs_rdcts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:22:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/26 17:15:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_cmd	*get_first_cmd(t_cmd *cmd, t_dlk_list *tmp)
{
	while (tmp != NULL)
	{
		if (tmp->token != NULL)
		{
			cmd = tmp;
			return (cmd);
		}
		else
			tmp = tmp->next;
	}
	return (cmd);
}

static t_cmd	*get_next_cmd(t_cmd *cmd, t_dlk_list *tmp)
{
	while (tmp != NULL)
	{
		if (tmp->token != NULL)
		{
			cmd = tmp->cmd;
			return (cmd);
		}
		else
			tmp = tmp->next;
	}
	return (cmd);
}

static t_cmd	*get_cmd(t_dlk_list *dlk, t_cmd *cmd)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	if (cmd == NULL)
		cmd = get_first_cmd(cmd, tmp);
	else if (dlk->pipeline == 1)
		cmd = get_next_cmd(cmd, tmp);
	return (cmd);
}

t_dlk_list	*performs_redirection(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_cmd		*cmd;

	tmp = dlk;
	dlk = init_dlk_redirect(dlk);
	cmd = NULL;
	while (tmp != NULL)
	{
		cmd = get_cmd(tmp, cmd);
		if (tmp->upper_rafter == 1)
			tmp = redirect_ur(tmp, cmd);
		else if (tmp->double_upper_rafter == 1)
			tmp = redirect_d_ur(tmp, cmd);
		tmp = tmp->next;
	}
	return (dlk);
}
