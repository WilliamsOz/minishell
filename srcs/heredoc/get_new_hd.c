/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_hd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:48:18 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/22 20:55:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*cpy_new_hd(char *buffer, char **env, char *tmp, int i)
{
	int	j;

	j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '$'
			&& existing_expand(buffer + i + 1, env, 0, 0) == TRUE)
		{
			tmp = copy_expanded_value(buffer + i + 1, env, tmp, &j);
			i += get_end_of_expansion(buffer + i + 1, env, 0, 0);
		}
		else if (buffer[i] == '$')
			i = skip_unk_exp(buffer, i);
		else
			tmp[j++] = buffer[i++];
	}
	return (tmp);
}

char	*get_new_hd(t_minishell *m, char *buffer, char **env, int i)
{
	int		len;
	char	*tmp;

	tmp = NULL;
	if (expansion_needed(buffer, i) == FALSE)
		return (buffer);
	len = get_new_heredoc_len(buffer, env, 0, 0);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
	{
		strerror(errno);
		close_heredoc_pipes(m->d_lk);
		m = destroy_all_data(m);
		exit (EXIT_FAILURE);
	}
	tmp = cpy_new_hd(buffer, env, tmp, 0);
	free(buffer);
	buffer = tmp;
	return (buffer);
}
