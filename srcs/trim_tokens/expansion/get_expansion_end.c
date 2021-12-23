/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expansion_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:15:12 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 17:59:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	get_end_of_expansion(char *token, int i)
{
	while (token[i] != '\0' && still_env_key(token[i]) == TRUE)
		i++;
	i++;
	return (i);
}
