/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_tab_env_failed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:49:22 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/30 12:55:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	mall_str_tab_env_failed(t_minishell *m)
{
	int i;

	strerror(errno);
	i = 0;
	while (m->tab_env[i] != NULL)
	{
		free(m->tab_env[i]);
		i++;
	}
	free(m->tab_env);
	env_destructor(m->env);
	cmd_destructor(m->cmd);
	m = destroy_all_data(m);
	exit (errno);
}

void	mall_tab_env_failed(t_minishell *m)
{
	strerror(errno);
	env_destructor(m->env);
	cmd_destructor(m->cmd);
	m = destroy_all_data(m);
	exit (errno);
}
