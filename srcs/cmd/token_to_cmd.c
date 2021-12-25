/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:56:07 by user42            #+#    #+#             */
/*   Updated: 2021/12/25 15:22:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void init_cmd_failed(t_minishell *m)
{
	strerror(errno);
	m = destroy_all_data(m);
	exit (EXIT_FAILURE);
}

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

t_dlk_list	*get_tab_cmd(t_minishell *m, t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->token != NULL)
		{
			if (tmp->next == NULL)
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
		}
		else
			tmp = tmp->next;
	}
	return (dlk);
}
