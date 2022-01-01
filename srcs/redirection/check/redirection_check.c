/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:40:06 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/01 19:02:29 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	redirection_check(t_minishell *m)
{
	t_dlk_list	*tmp;

	tmp = m->d_lk;
	while (tmp != NULL)
	{
		if (tmp->lower_rafter && lr_bad_redirection(m, tmp) == TRUE)
			return (TRUE);
		else if ((tmp->upper_rafter || tmp->double_upper_rafter)
			&& ur_bad_redirection(m, tmp) == TRUE)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}
