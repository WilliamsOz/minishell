/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/26 17:14:01 by wiozsert         ###   ########.fr       */
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

void	print_cmd(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	int			i;

	tmp = dlk;
	while (tmp != NULL)
	{
		i = 0;
		if (tmp->cmd != NULL)
		{
			while (tmp->cmd[i] != NULL)
			{
				REDCLR
				if (i == 0)
					printf("Command 1 : ");
				else
					printf("Command %d : ", i + 1);
				printf("|%s|\n", tmp->cmd[i]);
				STOPCLR
				i++;
			}
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

t_cmd	*init_cmd(t_minishell *m, t_dlk_list *dlk, int len)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->cmd != NULL)
			len += 1;
		tmp = tmp->next;
	}
	PD(len)
	return (m->cmd);
}

t_minishell	*get_cmd(t_minishell *m, t_dlk_list *dlk)
{
	dlk = memset_cmd(dlk);
	dlk = get_tab_cmd(m, dlk);
	m->cmd = init_cmd(m, dlk, 0);
	return (m);
}

t_minishell	*treat_data(t_minishell *minishell)
{
	t_dlk_list	*dlk;

	dlk = minishell->d_lk;
	if (redirection_check(minishell) == TRUE)
	{
		close_heredoc_pipes(minishell->d_lk);
		minishell->d_lk = double_lk_destroyer(minishell->d_lk);
		return (minishell);
	}
	minishell = trim_token(minishell);
	minishell = get_cmd(minishell, dlk);
	dlk = leave_one_token(dlk);
	dlk = performs_redirection(dlk);

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
			SMDLK
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
		signal_handler = 0;
		handle_rl_signal();
		minishell->line = NULL;
		minishell->line = readline("minishell>$ ");
		if (minishell->line == NULL)
		{
			minishell_eof_called();
			break ;
		}
		if (minishell->line != NULL)
			minishell = start_minishell(minishell);
	}
	destroy_all_data(minishell);
}
//ajouter free_env dans destroy all data et free le var 1 meme si il est == NULL
int	main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	// att = isatty(STDIN_FILENO);
	(void)av;
	if (ac != 1)
		return (0);
	minishell = minishell_creator(env);
	minishell->parsing_err = parsing_err_creator();
	if (minishell->parsing_err == NULL)
	{
		minishell_destroyer(minishell);
		exit (EXIT_FAILURE);
	}
	signal_handler = 0;
	minishell_core(minishell);
	return (0);
}
