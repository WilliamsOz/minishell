/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:02:34 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:41:03 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	get_status_len(int *ptr_i, int tmp)
{
	int	len;

	*ptr_i += 2;
	len = 1;
	while (tmp >= 10)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}
