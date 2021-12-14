/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_unknow_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:08:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/14 12:33:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	skip_unk_exp(char *token, int i)
{
	i++;
	while (token[i] != '\0'
		&& ((token[i] >= 'a' && token [i] <= 'z')
		|| (token[i] >= 'A' && token[i] <= 'Z') || token[i] == '_'))
		i++;
	return (i);
}
