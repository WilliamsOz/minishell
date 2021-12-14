/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_new_hd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:16:31 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/14 12:23:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	get_new_heredoc_len(char *buffer, char **env, int i, int len)
{
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '$'
			&& existing_expand(buffer + i + 1, env, 0, 0) == TRUE)
			len += get_expanded_len(buffer + i + 1, &i, 0, env);
		else if (buffer[i] == '$')
			i = skip_unk_exp(buffer, i);
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}
