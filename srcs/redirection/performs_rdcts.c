/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performs_rdcts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:22:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/27 16:07:45 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// t_dlk_list	*redirect_ur(t_minishell *m, t_dlk_list *dlk, t_cmd *tmp_cmd)
// {
// 	t_dlk_list	*keep;
// 	t_dlk_list	

// 	keep = dlk->next->next;


// 	t_dlk_list	*tmp;
// 	t_dlk_list	*keep;

// 	keep = dlk->next->next;
// 	tmp = dlk->next;
// 	dlk->file = tmp->token;
// 	free(tmp);
// 	dlk->next = keep;
// 	dlk->fd_file = open(dlk->file, O_CREAT | O_TRUNC,
// 		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
// 	cmd->output = dlk->fd_file;
// 	return (dlk);
// }

// t_dlk_list	*performs_redirection(t_minishell *m)
// {
// 	t_dlk_list	*tmp_dlk;
// 	t_cmd		*tmp_cmd;

// 	tmp_dlk = m->d_lk;
// 	tmp_cmd = m->cmd;
// 	tmp_dlk = init_dlk_redirect(tmp_dlk);
// 	while (tmp != NULL)
// 	{
// 		if (tmp->pipeline == 1)
// 			tmp_cmd = tmp_cmd->next;
// 		else if (tmp->upper_rafter == 1)
// 			m = redirect_ur(m, tmp_dlk, tmp_cmd);
// 		// else if (tmp->double_upper_rafter == 1)
// 			// m = redirect_d_ur(tmp, cmd);
// 		// else if (tmp->lower_rafter == 1)
// 			// m =
// 		// else if (tmp->here_doc == 1)
// 			// m = 
// 		else
// 			tmp = tmp->next;
// 	}
// 	return (dlk);
// }
