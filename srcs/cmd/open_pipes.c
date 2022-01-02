/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 09:25:48 by user42            #+#    #+#             */
/*   Updated: 2022/01/01 23:12:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_cmd	*memset_pipes(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		tmp->pipes[0] = -1;
		tmp->pipes[1] = -1;
		tmp = tmp->next;
	}
	return (cmd);
}

static void	pipes_opening_failed(t_minishell *m)
{
	strerror(errno);
	env_destructor(m->env);
	cmd_destructor(m->cmd);
	m = destroy_all_data(m);
	exit (errno);
}

t_minishell	*open_pipes(t_minishell *m)
{
	t_cmd	*tmp;
	int		ind;

	m->cmd = memset_pipes(m->cmd);
	tmp = m->cmd;
	while (tmp != NULL)
	{
		ind = pipe(tmp->pipes);
		if (ind == -1)
			pipes_opening_failed(m);
		tmp = tmp->next;
	}
	return (m);
}
