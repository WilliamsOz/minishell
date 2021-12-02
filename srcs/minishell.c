/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 15:42:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_minishell	*quotes_not_closed(t_minishell *minishell)
{
	ft_putstr_fd("Unclosed quotes detected\n", 2);
	free_line(minishell->line);
	return (minishell);
}

void	exit_called(t_minishell *minishell)
{
	parsing_err_destroyer(minishell->parsing_err);
	free_line(minishell->line);
	minishell_destroyer(minishell);
	exit (EXIT_SUCCESS);
}

void	minishell_core(t_minishell *minishell, int ac, char **av, char **env)
{
	minishell->line = readline("minishell>");
	while (minishell->line != NULL)
	{
		if (quotes_closed(minishell->parsing_err, 0, minishell->line) == FALSE)
			minishell = quotes_not_closed(minishell);
		else if (ft_strcmp(minishell->line, "exit") == 1)
			exit_called(minishell);
		if (minishell->line != NULL)
			minishell->line = free_line(minishell->line);
		if (minishell->parsing_err->exit_called == 0)
			minishell->line = readline("minishell>");
	}
	(void)ac;
	(void)av;
	(void)env;
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	minishell = minishell_creator();
	minishell->parsing_err = parsing_err_creator();
	if (minishell->parsing_err == NULL)
	{
		minishell_destroyer(minishell);
		exit (EXIT_FAILURE);
	}
	minishell_core(minishell, ac, av, env);
	return (0);
}
