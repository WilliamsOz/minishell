/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rafters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:30:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 14:45:24 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_rafter_errors(t_dlk_list *dlk)
{
	if (dlk->lower_rafter == 1 && lower_rafter_errors(dlk) == 1)
		return (TRUE);
	else if (dlk->upper_rafter == 1 && upper_rafter_errors(dlk) == 1)
		return (TRUE);
	return (FALSE);
}
