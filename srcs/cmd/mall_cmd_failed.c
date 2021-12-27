/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_cmd_failed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:18:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/27 15:19:13 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	mall_root_cmd_failed(t_minishell *m)
{
	strerror(errno);
	env_destructor(m->env);
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
	env_destructor(m->env);
	m = destroy_all_data(m);
	exit (errno);
}
