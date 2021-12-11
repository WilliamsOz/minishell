/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:10:34 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/11 15:30:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	get_expanded_len(char *token, int *ptr_i, int j, char **env)
{
	int	i;
	int	len;

	len = 0;
	*ptr_i += 1;
	i = get_expanded_index(token, env, 0, 0);
	while (env[i][j] != '=')
	{
		j++;
		*ptr_i += 1;
	}
	while (env[i][j] != '\0')
	{
		j++;
		if (env[i][j] != '\0')
			len++;
	}
	return (len);
}
