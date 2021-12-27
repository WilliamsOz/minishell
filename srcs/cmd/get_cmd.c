/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:45:08 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/27 22:08:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*find_cmd_path(char *cmd, t_env *env) // trouver et stocker le path de la commande
{
	char	*path;

	
}

t_cmd	*get_cmd_path(t_cmd *cmd, t_env *env)
{
	t_cmd	*tmp_cmd;
	t_env	*tmp_env;

	cmd = init_cmd_path(cmd);
	tmp_cmd = cmd;
	while (tmp_cmd != NULL)
	{
		tmp_env = env;
		cmd->path = find_cmd_path(cmd->cmd[0], tmp_env);
		tmp_cmd = tmp_cmd->next;
	}
	return (cmd);
}

t_minishell	*get_cmd(t_minishell *m, t_dlk_list *dlk)
{
	m->cmd = init_cmd(m, dlk);
	m = performs_redirection(m);
	dlk = memset_dlk_cmd(dlk);
	dlk = get_dlk_cmd(m, dlk);
	m->cmd = cpy_cmd_from_dlk(m->cmd, dlk);
	m->cmd = get_cmd_path(m->cmd, m->env);
	return (m);
}
