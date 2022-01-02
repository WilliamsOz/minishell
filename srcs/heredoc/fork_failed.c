/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_failed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:37:58 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 18:18:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	fork_failed(t_minishell *m)
{
	strerror(errno);
	m->cmd = cmd_destructor(m->cmd);
	m->env = env_destructor(m->env);
	m = destroy_all_data(m);
	exit (errno);
}
