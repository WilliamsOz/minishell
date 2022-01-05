/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:47:04 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 17:13:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_cmd	*get_new_node_cmd(t_minishell *m, t_cmd *root)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new == NULL)
		mall_new_cmd_failed(m);
	new->next = NULL;
	new->cmd = NULL;
	new->input = STDIN_FILENO;
	new->output = STDOUT_FILENO;
	new->status = 0;
	tmp = root;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (root);
}

t_cmd	*init_cmd(t_minishell *m, t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_cmd		*root;

	root = (t_cmd *)malloc(sizeof(t_cmd));
	if (root == NULL)
		mall_root_cmd_failed(m);
	root->next = NULL;
	root->cmd = NULL;
	root->input = STDIN_FILENO;
	root->output = STDOUT_FILENO;
	root->status = 0;
	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->pipeline)
			root = get_new_node_cmd(m, root);
		tmp = tmp->next;
	}
	return (root);
}
