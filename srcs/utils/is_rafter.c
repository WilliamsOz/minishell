/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rafter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:51:37 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/27 14:58:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_rafter(t_dlk_list *dlk)
{
	if (dlk != NULL && (dlk->upper_rafter || dlk->double_upper_rafter
		|| dlk->lower_rafter || dlk->here_doc))
		return (TRUE);
	return (FALSE);
}
