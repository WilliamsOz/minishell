/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:45:08 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 18:35:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd	*get_previous(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*next;

	tmp = cmd;
	if (tmp != NULL)
		tmp->previous = NULL;
	while (tmp != NULL)
	{
		next = tmp->next;
		if (next != NULL)
			next->previous = tmp;
		tmp = tmp->next;
	}
	return (cmd);
}

t_minishell	*get_cmd(t_minishell *m)
{
	m->cmd = init_cmd(m, m->d_lk);
	m = open_pipes(m);
	m = performs_redirection(m);
	m->d_lk = memset_dlk_cmd(m->d_lk);
	m->d_lk = get_dlk_cmd(m, m->d_lk);
	m->cmd = cpy_cmd_from_dlk(m->cmd, m->d_lk);
	m->cmd = get_previous(m->cmd);
	m->cmd = find_and_get_path_cmd(m, m->cmd, m->env);
	return (m);
}
