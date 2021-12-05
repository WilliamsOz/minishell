/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:25:42 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/05 15:25:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// || en 1er, | en 2eme < en 3eme

//verifier les pipelines errors
//faire les rafter errors

static t_parsing_err	*_init_parsing_errors_(t_parsing_err *errors)
{
	errors->pipeline_next_to_null = 0;
	return (errors);
}

static int	_is_there_tokens_errors_(t_parsing_err *errors)
{
	if (errors->pipeline_next_to_pipe == TRUE)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `||'\n", 2);
		return (TRUE);
	}
	else if (errors->pipeline_next_to_null == TRUE)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

t_minishell	*check_tokens_errors(t_minishell *minishell)
{
	if (check_special_chars(minishell->d_lk) == TRUE)
	{
		minishell = special_char_found(minishell);
		return (minishell);
	}
	minishell->parsing_err = _init_parsing_errors_(minishell->parsing_err);
	minishell = check_pipeline_errors(minishell, minishell->d_lk);
		// check_rafter_errors(minishell->d_lk) == 1)
	if (_is_there_tokens_errors_(minishell->parsing_err) == TRUE)
	{
		if (minishell->parsing_err != NULL)
			parsing_err_destroyer(minishell->parsing_err);
		if (minishell->d_lk != NULL)
			double_lk_destroyer(minishell->d_lk);
		return (minishell);
	}
	return (minishell);
}
