/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_destructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:32:38 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 18:38:28 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd	*cmd_destructor(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	while (cmd != NULL)
	{
		i = 0;
		tmp = cmd;
		cmd = cmd->next;
		while (tmp->cmd[i] != NULL)
		{
			free(tmp->cmd[i]);
			tmp->cmd[i] = NULL;
			i++;
		}
		if (tmp->path != NULL)
		{
			free(tmp->path);
			tmp->path = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
	return (cmd);
}
