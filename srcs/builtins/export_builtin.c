/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:13:03 by oozsertt          #+#    #+#             */
/*   Updated: 2021/12/30 18:38:09 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	export_builtin(t_cmd *cmd, t_env **env)
{
	t_env	*last_node;
	t_env	*new_node;

	if (cmd->cmd[1] == NULL)
		return ;
	last_node = *env;
	while (last_node->next != NULL)
		last_node = last_node->next;
	new_node = (t_env *)malloc(sizeof(t_env));
	if (new_node == NULL)
		return ;
	new_node->var = ft_strdup(cmd->cmd[1]);
	if (new_node->var == NULL)
		return ;
	last_node->next = new_node;
	new_node->next = NULL;
}
