/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_token_untill_next_cote.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:58:30 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 12:39:16 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static t_dlk_list *__manage_dlk_cote_data__(t_dlk_list *dlk, char c)
{
	if (dlk->double_quote == 0 &&
		dlk->simple_quote == 1 && c == SIMPLE_COTE)
		dlk->simple_quote--;
	else if (dlk->double_quote == 0 &&
		dlk->simple_quote == 0 && c == SIMPLE_COTE)
		dlk->simple_quote++;
	if (dlk->simple_quote == 0 &&
		dlk->double_quote == 1 && c == DOUBLE_COTE)
		dlk->double_quote--;
	else if (dlk->simple_quote == 0 &&
		dlk->double_quote == 0 && c == DOUBLE_COTE)
		dlk->double_quote++;
	return (dlk);
}

static int	__is_there_quotes_end__(t_dlk_list *dlk, char c)
{
	if (dlk->simple_quote == 0 && dlk->double_quote == 0 &&
		(c == '\0' || c == ' '))
		return (1);
	return (0);
}

static char	*__cpy_token__(char *str, int i, int j)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (j + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[j] = '\0';
	while (--j >= 0)
	{
		i--;
		tmp[j] = str[i];
	}
	return (tmp);
}

t_dlk_list	*get_coted_token(t_dlk_list *dlk, char *str, int *p_i, int j)
{
	int		i;

	i = *p_i;
	dlk->quote_ind = 1;
	while (dlk->quote_ind == 1)
	{
		dlk = __manage_dlk_cote_data__(dlk, str[i]);
		if (__is_there_quotes_end__(dlk, str[i]) == 1)
			dlk->quote_ind = 0;
		else
		{
			i++;
			j++;
		}
	}
	*p_i = i;
	dlk->token = __cpy_token__(str, i, j);
	return (dlk);
}
