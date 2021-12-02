/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err_creator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:25:13 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 13:33:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*parsing_err_creator(t_minishell *minishell)
{
	minishell->parsing_err = (t_parsing_err*)malloc(sizeof(t_parsing_err));
	if (minishell->parsing_err == NULL)
	{
		minishell_destroyer(minishell);
		strerror(errno);
		exit (EXIT_FAILURE);
	}
	minishell->parsing_err->exit_called = 0;
	return (minishell);
}
