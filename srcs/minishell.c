/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 17:04:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL
void    show_dlk(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	if (dlk == NULL)
	{
		printf("La double_lk est vide\n");
		return ;
	}
	tmp = dlk;
	while (tmp != NULL)
	{
		printf("\n");
		if (tmp->token != NULL)
		{
			BLUECLR
			printf("Token :\n");
			PS(tmp->token)
			STOPCLR
			printf("\n");
		}
		else if (tmp->is_metacharacter == 1)
		{
			YELLOWCLR
			if (tmp->here_doc == 1)
				printf("Here_doc\n");
			else if (tmp->double_upper_rafter == 1)
				printf("Double Upper Rafter\n");
			else if (tmp->pipeline == 1)
				printf("Pipeline\n");
			else if (tmp->lower_rafter == 1)
				printf("Lower Rafter\n");
			else if (tmp->upper_rafter == 1)
				printf("Upper Rafter\n");
			STOPCLR
			printf("\n");
		}
		tmp = tmp->next;
	}
}
//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

/*
Redirection :
< doit redigirer l'entree
> doit rediriger la sortie en mode TRUNC
>> doit rediriger la sortie en mode APPEND

Pipes | :
La sortie de chaque commande est connecter via
pipe a l'entree de la prochaine commande
*/

t_minishell	*treat_data(t_minishell *minishell, char **env)
{
	t_dlk_list	*dlk;

	dlk = minishell->d_lk;
	(void)env;
	dlk = heredoc(minishell, dlk, env);
	if (redirection_check(minishell, env) == TRUE)
	{
		close_heredoc_pipes(minishell->d_lk);
		minishell->d_lk = double_lk_destroyer(minishell->d_lk);
		return (minishell);
	}
	minishell = trim_token(minishell, env);
	SMDLK
	// dlk = performs_redirection(dlk); //next to-do
	// while (dlk != NULL)
	// {
		// if (dlk->previous == NULL)
			// first_entry(dlk);
		// else if (dlk->next != NULL)
			// second_entry();
		// else
			// last_entry();
		// dlk = dlk->next;
	// }
	return (minishell);
}

t_minishell	*start_minishell(t_minishell *minishell, char **env)
{
	minishell = are_quotes_closed(minishell, 0, minishell->line);
	if (minishell->line != NULL && minishell->line[0] != '\0')
	{
		add_history(minishell->line);
		minishell->d_lk = double_lk_creator(minishell,
			minishell->line, 0);
		minishell = is_logic_input(minishell);
		if (minishell->line != NULL)
		{
			SMDLK
			minishell = treat_data(minishell, env);
			minishell->line = free_line(minishell->line);
		}
	}
	return (minishell);
}

void	minishell_core(t_minishell *minishell, int ac, char **av, char **env)
{
	while (1)
	{
		minishell->line = NULL;
		minishell->sa.sa_handler = handle_rl_sigint;
		sigaction(SIGINT, &minishell->sa, NULL);
		if (minishell->line == NULL && signal_handler != SIGINT)
			minishell->line = readline("minishell>$ ");
		if (minishell->line == NULL)
		{
			minishell_eof_called();
			break ;
		}
		else if (minishell->line != NULL)
			minishell = start_minishell(minishell, env);
	}
	(void)ac;
	(void)av;
	destroy_all_data(minishell);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	if (ac != 1)
		exit (EXIT_FAILURE);
	minishell = minishell_creator();
	minishell->parsing_err = parsing_err_creator();
	if (minishell->parsing_err == NULL)
	{
		minishell_destroyer(minishell);
		exit (EXIT_FAILURE);
	}
	signal_handler = 0;
	minishell_core(minishell, ac, av, env);
	return (0);
}

//pour les built in pour setenv et unsetenv (export et unset)
//regarder les fonctions qui existe
//et les suivre pour les refaire
