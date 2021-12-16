/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_protection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:51:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 15:28:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void		init_dlk_creator_failed(t_minishell *minishell)
{
	strerror(errno);
	parsing_err_destroyer(minishell->parsing_err);
	free_line(minishell->line);
	minishell_destroyer(minishell);
	exit (EXIT_FAILURE);
}

void		init_dlk_token_failed(t_minishell *minishell)
{
	strerror(errno);
	minishell->d_lk = double_lk_destroyer(minishell->d_lk);
	parsing_err_destroyer(minishell->parsing_err);
	free_line(minishell->line);
	minishell_destroyer(minishell);
	exit (EXIT_FAILURE);
}
