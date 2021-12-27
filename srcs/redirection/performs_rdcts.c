/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performs_rdcts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:22:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/27 18:26:15 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*previous_null(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	dlk = dlk->next;
	free(tmp);
	tmp = dlk;
	dlk = dlk->next;
	free(tmp->token);
	free(tmp);
	if (dlk != NULL)
		dlk->previous = NULL;
	return (dlk);
}

t_dlk_list	*previous_not_null(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	tmp = dlk;
	keep = dlk->next;
	dlk = dlk->previous;
	free(tmp);
	dlk->next = keep;
	tmp = keep;
	keep = keep->next;
	free(tmp->token);
	free(tmp);
	dlk->next = keep;
	return (dlk);
}

t_minishell	*redirect_ur(t_minishell *m, t_dlk_list **dlk, t_cmd **tmp_cmd)
{
	(*dlk)->fd_file = open((*dlk)->next->token, O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if ((*tmp_cmd)->output != STDOUT_FILENO)
		close((*tmp_cmd)->output);
	(*tmp_cmd)->output = (*dlk)->fd_file;
	if ((*dlk)->previous == NULL)
	{
		(*dlk) = previous_null((*dlk));
		m->d_lk = (*dlk);
	}
	else
		(*dlk) = previous_not_null((*dlk)); //modify
	return (m);
}

t_minishell	*performs_redirection(t_minishell *m)
{
	t_dlk_list	*tmp_dlk;
	t_cmd		*tmp_cmd;

	t_minishell *minishell = m;
	tmp_dlk = m->d_lk;
	tmp_cmd = m->cmd;
	tmp_dlk = init_dlk_redirect(tmp_dlk);
	while (tmp_dlk != NULL)
	{
		if (tmp_dlk->pipeline == 1)
		{
			// PD(tmp_cmd->output)
			tmp_cmd = tmp_cmd->next;
			tmp_dlk = tmp_dlk->next;
		}
		else if (tmp_dlk->upper_rafter == 1)
		{
			m = redirect_ur(m, &tmp_dlk, &tmp_cmd);
			SMDLK
		}
		// else if (tmp->double_upper_rafter == 1)
			// m = redirect_d_ur(tmp, cmd);
		// else if (tmp->lower_rafter == 1)
			// m =
		// else if (tmp->here_doc == 1)
			// m = 
		else
			tmp_cmd = tmp_cmd->next;
	}
	ICI
	PD(tmp_cmd->output)
	return (m);
}
