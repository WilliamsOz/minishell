/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:37:47 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/07 16:38:04 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*destroy_all_data(t_minishell *minishell)
{
	if (minishell->parsing_err != NULL)
		parsing_err_destroyer(minishell->parsing_err);
	if (minishell->d_lk != NULL)
		double_lk_destroyer(minishell->d_lk);
	if (minishell->line != NULL)
		minishell->line = free_line(minishell->line);
	if (minishell != NULL)
		minishell_destroyer(minishell);
	return (minishell);
}
