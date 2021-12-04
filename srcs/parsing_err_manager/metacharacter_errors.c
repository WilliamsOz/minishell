/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metacharacter_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:25:42 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/04 17:20:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// int	check_rafter_errors(t_dlk_list *dlk)
// {
	

// 	return (0);
// }

t_minishell	*check_metacharacter_errors(t_minishell *minishell)
{
	if (check_pipeline_errors(minishell->d_lk) == 1)
	{
		if (minishell->parsing_err != NULL)
			parsing_err_destroyer(minishell->parsing_err);
		if (minishell->d_lk != NULL)
			double_lk_destroyer(minishell->d_lk);
		return (minishell);
	}
	// else if (check_rafter_errors(minishell->d_lk) == 1)
	// {
	// 	if (minishell->parsing_err != NULL)
	// 		parsing_err_destroyer(minishell->parsing_err);
	// 	if (minishell->d_lk != NULL)
	// 		double_lk_destroyer(minishell->d_lk);
	// 	return (minishell);
	// }
	return (minishell);
}
