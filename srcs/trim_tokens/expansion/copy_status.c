/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:19:20 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/15 19:18:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*cpy_status(char *tmp, int s_h, int *ptr_i, int *ptr_j)
{
	char	*get_status;
	int		i;

	get_status = NULL;
	get_status = ft_itoa(s_h);
	i = 0;
	while (get_status[i] != '\0')
	{
		tmp[*ptr_j] = get_status[i];
		*ptr_j += 1;
		i++;
	}
	free(get_status);
	*ptr_i += 2;
	return (tmp);
}
