/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:25:42 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 15:28:43 by wiozsert         ###   ########.fr       */
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
		else if (tmp->pipeline == 1 && check_pipeline_errors(tmp) == 1)
			return (TRUE);
		else if ((tmp->lower_rafter == 1 || tmp->upper_rafter == 1) &&
				check_rafter_errors(tmp) == 1)
			return (TRUE);
		else if (tmp->double_upper_rafter == 1 &&
				check_double_upper_rafter(tmp) == 1)
			return (TRUE);
		tmp = tmp->next;
	}
	return(FALSE);
}

static t_minishell	*__special_char_found__(t_minishell *minishell)
{
	if (minishell->d_lk != NULL)
		minishell->d_lk = double_lk_destroyer(minishell->d_lk);
	if (minishell->line != NULL)
		minishell->line = free_line(minishell->line);
	return (minishell);
}

t_minishell	*is_logic_input(t_minishell *minishell)
{
	if (is_pipeline_next_to_cmd(minishell->d_lk) == TRUE ||
		check_special_chars(minishell->d_lk) == TRUE)
	{
		minishell = __special_char_found__(minishell);
		return (minishell);
	}
	if (__check_all_tokens_errors__(minishell) == TRUE)
	{
		if (minishell->d_lk != NULL)
			minishell->d_lk = double_lk_destroyer(minishell->d_lk);
		if (minishell->line != NULL)
			minishell->line = free_line(minishell->line);
	}
	return (minishell);
}
