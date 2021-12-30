/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_failed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:37:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/30 09:39:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	fork_failed(t_minishell *m)
{
	strerror(errno);
	cmd_destructor(m->cmd);
	env_destructor(m->env);
	m = destroy_all_data(m);
	exit (errno);
}
