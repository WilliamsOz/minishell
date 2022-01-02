/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:55:23 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 18:36:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd	*init_cmd_path(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		tmp->path = NULL;
		tmp = tmp->next;
	}
	return (cmd);
}
