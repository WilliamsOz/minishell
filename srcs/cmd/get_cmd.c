/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:45:08 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/29 02:03:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*get_cmd(t_minishell *m)
{
	m->cmd = init_cmd(m, m->d_lk);
	m = performs_redirection(m);
	m->d_lk = memset_dlk_cmd(m->d_lk);
	m->d_lk = get_dlk_cmd(m, m->d_lk);
	m->cmd = cpy_cmd_from_dlk(m->cmd, m->d_lk);
	m->cmd = find_and_get_path_cmd(m, m->cmd, m->env);
	return (m);
}
