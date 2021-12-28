/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:45:08 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/28 19:26:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*get_cmd(t_minishell *m, t_dlk_list *dlk)
{
	m->cmd = init_cmd(m, dlk);
	m = performs_redirection(m);
	dlk = memset_dlk_cmd(dlk);
	dlk = get_dlk_cmd(m, dlk);
	m->cmd = cpy_cmd_from_dlk(m->cmd, dlk);
	m->cmd = find_and_get_path_cmd(m, m->cmd, m->env);
	return (m);
}
