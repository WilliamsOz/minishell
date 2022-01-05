/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 14:56:55 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_minishell	*treat_data(t_minishell *minishell)
{
	if (redirection_check(minishell) == TRUE)
	{
		close_heredoc_pipes(minishell->d_lk);
		minishell->d_lk = double_lk_destroyer(minishell->d_lk);
		minishell->parsing_err = parsing_err_destroyer(minishell->parsing_err);
		return (minishell);
	}
	minishell = trim_token(minishell);
	minishell = get_cmd(minishell);
	minishell = tab_env_creator(minishell);
	execution(minishell, minishell->tab_env);
	minishell = destroy_cmd_data(minishell);
	return (minishell);
}

t_minishell	*start_minishell(t_minishell *minishell)
{
	minishell = are_quotes_closed(minishell, 0, minishell->line);
	if (minishell->line != NULL && minishell->line[0] != '\0')
	{
		add_history(minishell->line);
		minishell->d_lk = double_lk_creator(minishell,
				minishell->line, 0);
		minishell = is_logic_input(minishell);
		minishell = heredoc(minishell, minishell->d_lk);
		if (minishell->line != NULL)
		{
			minishell = treat_data(minishell);
			minishell->line = free_line(minishell->line);
		}
	}
	return (minishell);
}

void	minishell_core(t_minishell *minishell)
{
	while (1)
	{
		handle_rl_signal();
		minishell->line = NULL;
		minishell->line = readline("minishell>$ ");
		if (minishell->line == NULL)
		{
			minishell_eof_called();
			break ;
		}
		else
		{
			minishell->parsing_err = parsing_err_creator();
			if (minishell->parsing_err == NULL)
				init_parsing_failed(minishell);
			minishell = start_minishell(minishell);
			minishell = destroy_data(minishell);
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*minishell;
	int			att;

	(void)av;
	att = isatty(STDIN_FILENO);
	if (ac != 1 || att == 0)
		return (0);
	minishell = minishell_creator(env);
	g_signal_handler = 0;
	minishell_core(minishell);
	if (minishell->env != NULL)
		minishell->env = env_destructor(minishell->env);
	if (minishell != NULL)
		minishell_destroyer(minishell);
	return (g_signal_handler);
}
