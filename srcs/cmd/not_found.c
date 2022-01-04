/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_found.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:11:56 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 10:12:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	not_found(char **path, char **path_cmd)
{
	free(*path_cmd);
	*path_cmd = NULL;
	free(*path);
	*path = NULL;
}
