/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/15 19:01:58 by wiozsert         ###   ########.fr       */
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
<< read depuis une pipe
>> doit rediriger la sortie en mode APPEND

Pipes | :
La sortie de chaque commande est connecter via
pipe a l'entree de la prochaine commande
*/

// void	first_entry(t_dlk_list *dlk)
// {
// 	if (dlk->upper_rafter )
// }


t_minishell	*treat_data(t_minishell *minishell, char **env)
{
	t_dlk_list	*dlk;

	dlk = minishell->d_lk;
	(void)env;
	dlk = heredoc(minishell, dlk, env);
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
		minishell = is_logic_input(minishell, env);
		if (minishell->line != NULL)
		{
			SMDLK
			minishell = trim_token(minishell, env);
			minishell = treat_data(minishell, env);
			SMDLK
			minishell->line = free_line(minishell->line);
		}
	}
	return (minishell);
}

void	handler1(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		// write(1, "\nminishell>$ ", 14);
		signal_handler = 130;
	}
}

void	eof_called(void)
{
	if (signal_handler == 0)
		write(1, "exit\n", 5);
	else
		write(1, "exit", 5);
}

void	minishell_core(t_minishell *minishell, int ac, char **av, char **env)
{
	while (1)
	{
		minishell->sa.sa_handler = handler1;
		sigaction(SIGINT, &minishell->sa, NULL);
		if (signal_handler != SIGINT)
			minishell->line = readline("minishell>$ ");
		if (minishell->line == NULL)
		{
			eof_called();
			break ;
		}
		if (minishell->line != NULL)
			minishell = start_minishell(minishell, env);
	}
	(void)ac;
	(void)av;
	destroy_all_data(minishell);
}

/*

Chercher et lancer le bonne executable (base sur la variable PATH ou
en utilisant le chemin relatif ou absolu)

$? doit etre receptionne et renvoyer le
dernier status de la derniere commande

Ctrl-C && Ctrl-D && ctrl-\ doivent fonctionner comme
dans le bash (signaux)

Lorsqu'il est interactif :
Ctrl-C affiche un nouveau promt dans une nouvelle ligne
Ctrl-D exit le shell
Ctrl-\ ne fait rien

//pour les built in pour setenv et unsetenv (export et unset)
//regarder les fonctions qui existe
//et les suivre pour les refaire

*/

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
