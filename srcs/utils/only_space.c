/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:04:01 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/06 15:10:10 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_there_only_space(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->only_space == FALSE)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
