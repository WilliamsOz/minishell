/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:17:19 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/30 16:24:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*minishell_creator(char **env)
{
	t_minishell	*minishell;

	minishell = NULL;
	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	if (minishell == NULL)
	{
		strerror(errno);
		exit (EXIT_FAILURE);
	}
	minishell->line = NULL;
	minishell->parsing_err = NULL;
	minishell->d_lk = NULL;
	minishell->env = NULL;
	minishell->env = env_creator(minishell, env);
	return (minishell);
}
