/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:25:42 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/05 17:14:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	__check_all_tokens_errors__(t_minishell *minishell)
{
	t_dlk_list	*tmp;

	tmp = minishell->d_lk;
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1 && check_here_doc_errors(tmp) == 1)
			return (TRUE);
		if (tmp->pipeline == 1 && check_pipeline_errors(tmp) == 1)
			return (TRUE);
		else if ((tmp->lower_rafter == 1 || tmp->upper_rafter == 1) &&
			check_rafter_errors(tmp) == 1)
			return (TRUE);
	}
	return(FALSE);
}

t_minishell	*check_tokens_errors(t_minishell *minishell)
{
	if (check_special_chars(minishell->d_lk) == TRUE)
	{
		minishell = special_char_found(minishell);
		return (minishell);
	}
	if (__check_all_tokens_errors__(minishell) == TRUE)
	{
		if (minishell->parsing_err != NULL)
			parsing_err_destroyer(minishell->parsing_err);
		if (minishell->d_lk != NULL)
			double_lk_destroyer(minishell->d_lk);
	}
	return (minishell);
}
