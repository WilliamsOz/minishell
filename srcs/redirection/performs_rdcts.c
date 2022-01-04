/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performs_rdcts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:22:04 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 12:53:15 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*performs_redirection(t_minishell *m)
{
	t_dlk_list	*tmp_dlk;
	t_cmd		*tmp_cmd;

	m->d_lk = init_dlk_redirect(m->d_lk);
	tmp_dlk = m->d_lk;
	tmp_cmd = m->cmd;
	while (tmp_dlk != NULL)
	{
		if (tmp_dlk->pipeline == 1)
		{
			tmp_cmd = tmp_cmd->next;
			tmp_dlk = tmp_dlk->next;
		}
		else if (tmp_dlk->upper_rafter == 1)
			m = redirect_ur(m, &tmp_dlk, &tmp_cmd);
		else if (tmp_dlk->double_upper_rafter == 1)
			m = redirect_d_ur(m, &tmp_dlk, &tmp_cmd);
		else if (tmp_dlk->lower_rafter == 1)
			m = redirect_l_r(m, &tmp_dlk, &tmp_cmd);
		else if (tmp_dlk->here_doc == 1)
			m = redirect_hd(m, &tmp_dlk, &tmp_cmd);
		else
			tmp_dlk = tmp_dlk->next;
	}
	return (m);
}
