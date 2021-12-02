/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 13:34:51 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"



int	main(int ac, char **av, char **env) //installer readline
{
	t_minishell	*minishell;

	minishell = minishell_creator();
	minishell = parsing_err_creator(minishell);
	minishell(minishell);
	// minishell.line = readline("minishell> ");
	// while (minishell.line != NULL)
	// {
	// 	minishell = are_quotes_closed(minishell, 0);
	// 	if (ft_strcmp(minishell.line, "exit") == 1)
	// 	{
	// 		minishell.line = free_line(minishell.line);
	// 		return (0);
	// 	}
	// 	if (minishell.line != NULL)
	// 		minishell.line = free_line(minishell.line);
	// 	if (minishell.exit_called == 0)
	// 		minishell.line = readline("minishell> ");
	// }
	(void)ac;
	(void)av;
	(void)env;
	return (0);
}
