/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:09:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:40:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	execution(t_minishell *minishell, char **env)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = minishell->cmd;
	tmp_cmd = first_entry(minishell, tmp_cmd, env);
	while (tmp_cmd != NULL && tmp_cmd->next != NULL)
		tmp_cmd = mid_entry(minishell, tmp_cmd, env);
	tmp_cmd = last_entry(minishell, tmp_cmd, env);
}
