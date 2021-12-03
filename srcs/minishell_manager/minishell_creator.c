/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:17:19 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/03 19:09:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*minishell_creator(void)
{
	t_minishell	*minishell;

	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	if (minishell == NULL)
	{
		strerror(errno);
		exit (EXIT_FAILURE);
	}
	minishell->line = NULL;
	minishell->parsing_err = NULL;
	minishell->d_lk = NULL;
	return (minishell);
}
