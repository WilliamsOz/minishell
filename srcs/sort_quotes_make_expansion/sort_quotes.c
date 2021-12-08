/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:56 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 12:43:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*__sort_token_quotes__(char *token, int i, int j, int len)
{
	int		initial_token_len;
	char	*tmp;

	initial_token_len = ft_strlen(token);
	token = remove_useless_quotes(token);
	// ex
	(void)j;
	return (token);
}

static int	__is_need_to_sort__(char *token, int i)
{
	while (token[i] != '\0')
	{
		if (token[i] == SIMPLE_COTE || token[i] == DOUBLE_COTE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_dlk_list	*sort_quotes(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->token != NULL && __is_need_to_sort__(dlk->token, 0) == TRUE)
			dlk->token = __sort_token_quotes__(dlk->token, 0, 0, 0);
		tmp = tmp->next;
	}

	return (dlk);
}
