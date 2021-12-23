/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:25:42 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 14:42:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	_check_all_tokens_errors_(t_minishell *minishell, t_dlk_list **p)
{
	t_dlk_list	*tmp;

	tmp = minishell->d_lk;
	while (tmp != NULL)
	{
		*p = tmp;
		if (tmp->here_doc == 1 && check_here_doc_errors(tmp) == TRUE)
			return (TRUE);
		else if (tmp->pipeline == 1 && check_pipeline_errors(tmp) == TRUE)
			return (TRUE);
		else if ((tmp->lower_rafter == 1 || tmp->upper_rafter == 1) &&
				check_rafter_errors(tmp) == TRUE)
			return (TRUE);
		else if (tmp->double_upper_rafter == 1 &&
				check_double_upper_rafter(tmp) == TRUE)
			return (TRUE);
		tmp = tmp->next;
	}
	return(FALSE);
}

static t_minishell	*_special_char_found_(t_minishell *minishell)
{
	if (minishell->d_lk != NULL)
		minishell->d_lk = double_lk_destroyer(minishell->d_lk);
	if (minishell->line != NULL)
		minishell->line = free_line(minishell->line);
	return (minishell);
}

static void	heredoc_before_errors(t_minishell *m, t_dlk_list *keep)
{
	t_dlk_list	*tmp;

	tmp = m->d_lk;
	while (tmp != NULL && tmp != keep)
	{
		if (tmp->here_doc == 1 && tmp->limiter != NULL)
		{
			tmp = hd_prepare_dlk(tmp);
			// dlk = call_child(m, tmp, 0);
		}
		tmp = tmp->next;
	}
}

t_minishell	*is_logic_input(t_minishell *minishell)
{
	t_dlk_list	*keep;

	if (is_pipeline_next_to_cmd(minishell->d_lk) == TRUE ||
		check_special_chars(minishell->d_lk) == TRUE)
		minishell = _special_char_found_(minishell);
	else if (_check_all_tokens_errors_(minishell, &keep) == TRUE)
	{
		heredoc_before_errors(minishell, keep);
		// close all pipes
		if (minishell->d_lk != NULL)
			minishell->d_lk = double_lk_destroyer(minishell->d_lk);
		if (minishell->line != NULL)
			minishell->line = free_line(minishell->line);
	}
	return (minishell);
}
