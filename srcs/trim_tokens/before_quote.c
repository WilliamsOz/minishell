/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:09:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 18:59:55 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*before_quote(t_trim *trim, char *token, int *ptr_i, char **env)
{
	char	*tmp;
	int		len;
	int		i;

	i = *ptr_i;
	len = bc_get_len(token, &i, 0, env);
	PD(len)
	*ptr_i = i;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	tmp = bc_get_final_token(token, tmp, env, 0);
	trim->before_quote = tmp;
	return (trim->before_quote);
}
