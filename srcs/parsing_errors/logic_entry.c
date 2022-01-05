/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:25:42 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:38:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	check_all_tokens_errors(t_minishell *minishell, t_dlk_list **p)
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
		else if ((tmp->lower_rafter == 1 || tmp->upper_rafter == 1)
			&& check_rafter_errors(tmp) == TRUE)
			return (TRUE);
		else if (tmp->double_upper_rafter == 1
			&& check_double_upper_rafter(tmp) == TRUE)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

static t_minishell	*special_char_found(t_minishell *minishell)
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
	signal(SIGINT, hd_handler);
	signal(SIGQUIT, hd_handler);
	while (tmp != NULL && tmp != keep)
	{
		signal_handler = 0;
		if (tmp->here_doc == 1)
		{
			signal_handler = 0;
			tmp = hd_prepare_dlk(tmp);
			tmp = call_child(m, tmp, 0);
			close(tmp->heredoc_pipe[0]);
			close(tmp->heredoc_pipe[1]);
		}
		if (signal_handler == 130)
			break ;
		tmp = tmp->next;
	}
}

t_minishell	*is_logic_input(t_minishell *minishell)
{
	t_dlk_list	*keep;

	if (is_pipeline_next_to_cmd(minishell->d_lk) == TRUE
		|| check_special_chars(minishell->d_lk) == TRUE)
		minishell = special_char_found(minishell);
	else if (check_all_tokens_errors(minishell, &keep) == TRUE)
	{
		heredoc_before_errors(minishell, keep);
		if (minishell->d_lk != NULL)
			minishell->d_lk = double_lk_destroyer(minishell->d_lk);
		if (minishell->parsing_err != NULL)
			minishell->parsing_err
				= parsing_err_destroyer(minishell->parsing_err);
		if (minishell->line != NULL)
			minishell->line = free_line(minishell->line);
	}
	return (minishell);
}
