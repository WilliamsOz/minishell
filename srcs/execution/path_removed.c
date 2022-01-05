/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_removed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:56:47 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 13:04:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	path_removed(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
			&& env[i][3] == 'H' && env[i][4] == '=' && env[i][5] != '\0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
