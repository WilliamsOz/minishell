/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:45:18 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/05 15:27:28 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_unsuported_chars_(char c)
{
	if (c == BACKSLASH_CHAR || c == SEMICOLON)
		return (TRUE);
	return (FALSE);
}

static int	_is_there_special_char_(char *token)
{
	int		simple_cote_ind;
	int		i;

	simple_cote_ind = 0;
	i = 0;
	while (token[i] != '\0')
	{
		if (simple_cote_ind == 0 && token[i] == SIMPLE_COTE)
			simple_cote_ind++;
		else if (simple_cote_ind == 1 && token[i] == SIMPLE_COTE)
			simple_cote_ind--;
		if (simple_cote_ind == 0  && _unsuported_chars_(token[i]) == TRUE)
			return (TRUE);
		else
			i++;
	}
	return (FALSE);
}

int	check_special_chars(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->token != NULL && _is_there_special_char_(dlk->token) == TRUE)
			return (TRUE);
		else
			tmp = tmp->next;
	}
	return (FALSE);
}

t_minishell	*special_char_found(t_minishell *minishell)
{
	ft_putstr_fd("Unsuported character found\n", 2);
	if (minishell->parsing_err != NULL)
		parsing_err_destroyer(minishell->parsing_err);
	if (minishell->d_lk != NULL)
		double_lk_destroyer(minishell->d_lk);
	if (minishell != NULL)
		minishell_destroyer(minishell);
	return (minishell);
}
