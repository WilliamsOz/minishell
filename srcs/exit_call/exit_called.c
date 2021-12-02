/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_called.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:08:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 18:45:27 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exit_called(t_minishell *minishell)
{
	parsing_err_destroyer(minishell->parsing_err);
	free_line(minishell->line);
	minishell_destroyer(minishell);
	exit (EXIT_SUCCESS);
}
