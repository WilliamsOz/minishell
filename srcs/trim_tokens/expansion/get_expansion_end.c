/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:15:12 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 16:15:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	get_end_of_expansion(char *token, char **env, int i, int j)
{
	i = get_expanded_index(token, env, 0, 0);
	while (env[i][j] == token[j])
		j++;
	j++;
	return (j);
}
