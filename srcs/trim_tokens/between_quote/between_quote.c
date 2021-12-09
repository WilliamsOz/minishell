/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:55:27 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 17:07:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	move_index_untill_no_remaining_quote(char *token, int i)
{
	while(token[i] != '\0' && quotes_remaining(token + i, 0) == TRUE)
		i++;
	return (i);
}

char	*bw_get_final_token(char *token, char *tmp, char **env, int i)
{
	

	return (tmp);
}

char	*get_between_quote(t_trim *trim, char *token, int *ptr_i, char **env)
{
	char	*tmp;
	int		i;
	int		len;

	i = *ptr_i;
	len = get_between_len(token + i, env, 0, i);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	tmp = bw_get_final_token(token + i, tmp, env, i); //faire cette fct
	i = move_index_untill_no_remaining_quote(token, i);
	*ptr_i = i;
	return (trim->between_quote);
}
