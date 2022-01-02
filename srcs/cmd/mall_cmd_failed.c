/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_cmd_failed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:18:44 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 18:19:44 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	mall_root_cmd_failed(t_minishell *m)
{
	strerror(errno);
	m->env = env_destructor(m->env);
	m = destroy_all_data(m);
	exit (errno);
}

void	mall_new_cmd_failed(t_minishell *m)
{
	t_cmd	*tmp;

	strerror(errno);
	while (m->cmd != NULL)
	{
		tmp = m->cmd;
		m->cmd = m->cmd->next;
		free(tmp);
	}
	m->env = env_destructor(m->env);
	m = destroy_all_data(m);
	exit (errno);
}
