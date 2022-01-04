/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dlk_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:56:07 by user42            #+#    #+#             */
/*   Updated: 2022/01/04 13:22:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*get_one_cmd_tab(t_minishell *m, t_dlk_list *dlk)
{
	dlk->cmd = (char **)malloc(sizeof(char *) * 2);
	if (dlk->cmd == NULL)
		init_cmd_failed(m);
	dlk->cmd[0] = dlk->token;
	dlk->cmd[1] = NULL;
	return (dlk);
}

static int	get_len(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	int			len;

	len = 0;
	tmp = dlk;
	while (tmp != NULL && tmp->token != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_dlk_list	*get_cmd_and_flag_tab(t_minishell *m, t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	int			len;
	int			i;

	i = 0;
	len = get_len(dlk);
	dlk->cmd = (char **)malloc(sizeof(char *) * (len + 1));
	if (dlk->cmd == NULL)
		init_cmd_failed(m);
	dlk->cmd[len] = NULL;
	tmp = dlk;
	while (tmp != NULL && tmp->token != NULL)
	{
		dlk->cmd[i] = tmp->token;
		i++;
		tmp = tmp->next;
	}
	return (dlk);
}

t_dlk_list	*cpy_cmd(t_minishell *m, t_dlk_list *tmp)
{
	if (tmp->next == NULL
		|| (tmp->next != NULL && tmp->next->token == NULL))
	{
		tmp = get_one_cmd_tab(m, tmp);
		tmp = tmp->next;
	}
	else if (tmp->next != NULL && tmp->next->token != NULL)
	{
		tmp = get_cmd_and_flag_tab(m, tmp);
		while (tmp != NULL && tmp->token != NULL)
			tmp = tmp->next;
	}
	return (tmp);
}

t_dlk_list	*get_dlk_cmd(t_minishell *m, t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (is_rafter(tmp) == TRUE)
			tmp = tmp->next->next;
		else if (tmp->token != NULL)
			tmp = cpy_cmd(m, tmp);
		else
			tmp = tmp->next;
	}
	return (dlk);
}
