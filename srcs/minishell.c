/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 18:27:46 by wiozsert         ###   ########.fr       */
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

void	print_dlk_cmd(t_dlk_list *dlk)
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

void	print_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int			i;

	tmp = cmd;
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

//DELDELDELDELDELDELDELDELDELDELDELDELDsELDELDELDELDELDELDELDELDELDELDELDELDELDEL

void	execute_cmd(t_minishell *minishell, char **env)
{
	t_cmd	*tmp_cmd;

	signal(SIGCHLD, handle_sigchild);
	tmp_cmd = minishell->cmd;
	tmp_cmd = first_entry(minishell, tmp_cmd, env);
	while (tmp_cmd != NULL && tmp_cmd->next != NULL)
	{
		if (is_builtin(tmp_cmd->cmd[0]) == TRUE)
		{
			// prepare_fd_builtin();
			execute_builtin(minishell, tmp_cmd);
		}
		else
			rw_inside_pipes(minishell, tmp_cmd, env);
		tmp_cmd = tmp_cmd->next;
	}
	if (tmp_cmd != NULL)
		execute_last_cmd(minishell, tmp_cmd, env);
}

t_minishell	*destroy_data(t_minishell *m)
{
	m = tab_env_destructor(m);
	m->cmd = cmd_destructor(m->cmd);
	return (m);
}

t_minishell	*treat_data(t_minishell *minishell)
{
	if (redirection_check(minishell) == TRUE)
	{
		close_heredoc_pipes(minishell->d_lk);
		minishell->d_lk = double_lk_destroyer(minishell->d_lk);
		return (minishell);
	}
	minishell = trim_token(minishell);
	minishell = get_cmd(minishell); /* cmd && pipes */
	minishell = tab_env_creator(minishell); /* tab_env */
	execute_cmd(minishell, minishell->tab_env);
	return (minishell);
}

t_minishell	*start_minishell(t_minishell *minishell)
{
	minishell = are_quotes_closed(minishell, 0, minishell->line);
	if (minishell->line != NULL && minishell->line[0] != '\0')
	{
		add_history(minishell->line);
		minishell->d_lk = double_lk_creator(minishell,
			minishell->line, 0); /* d_lk */
		minishell = is_logic_input(minishell);
		minishell = heredoc(minishell, minishell->d_lk); /*hd_pipes */
		if (minishell->line != NULL)
		{
			minishell = treat_data(minishell);
			minishell->line = free_line(minishell->line);
			minishell = destroy_data(minishell);
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
			minishell = start_minishell(minishell);
	}
	minishell = destroy_all_data(minishell);
}
//ne pas oublier de free char **env
//close les pipes de la commandes pour tout les fails de malloc et a la fin
//ne pas faire l'expansion si il y a des cotes dans le limiter du heredoc
int	main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	// att = isatty(STDIN_FILENO);
	(void)av;
	if (ac != 1)
		return (0);
	minishell = minishell_creator(env); /* minishell && env */
	minishell->parsing_err = parsing_err_creator(); /* parsing */
	if (minishell->parsing_err == NULL)
	{
		minishell = minishell_destroyer(minishell);
		exit (errno);
	}
	signal_handler = 0;
	minishell_core(minishell);
	return (signal_handler);
}
