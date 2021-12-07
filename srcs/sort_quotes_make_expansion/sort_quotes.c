/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:56 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/07 17:05:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// static int	*get_final_lenght(char *token, int i, int len)
// {
// 	int		simple_cote;
// 	int		double_cote;

// 	simple_cote = 0;
// 	double_cote = 0;
// 	while (token[i] != '\0')
// 	{
// 		// if (token[i] == SIMPLE_COTE)
// 		i++;
// 	}
// 	return (i);
// }

// static char	*__sort_token_quotes__(char *token, int i, int j, int len)
// {
// 	char	*tmp;

// 	len = get_final_lenght(token, i, len);
// 	(void)j;
// 	return (token);
// }

// static int	__quotes_need_sort__(char *token, int i)
// {
// 	while (token[i] != '\0')
// 	{
// 		if (token[i] == SIMPLE_COTE || token[i] == DOUBLE_COTE)
// 			return (TRUE);
// 		i++;
// 	}
// 	return (FALSE);
// }

t_dlk_list	*sort_quotes(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		// if (tmp->token != NULL && __quotes_need_sort__(dlk->token, 0) == TRUE)
			// dlk->token = __sort_token_quotes__(dlk->token, 0, 0, 0);
		tmp = tmp->next;
	}

	return (dlk);
}
