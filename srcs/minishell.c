/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/13 13:03:35 by user42           ###   ########.fr       */
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

char	*expand_heredoc(char *buffer, int i)
{
	(void)i;
	PS(buffer)
	return (buffer);
}

int	expansion_needed(char *buffer, int i)
{
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '$')
			return (TRUE);
		else
			i++;
	}
	return (FALSE);
}

static int	get_new_heredoc_len(char *buffer, char **env, int i, int len)
{
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '$'
			&& existing_expand(buffer + i + 1, env, 0, 0) == TRUE)
			len += get_expanded_len(buffer + i + 1, &i, 0, env);
		else if (buffer[i] == '$')
		{
			i++;
			while (buffer[i] != '\0' && buffer[i] != ' ' && buffer[i] != '$'
				&& is_it_a_quote(buffer[i]) == FALSE)
				i++;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

static char	*get_new_heredoc(char *buffer, char **env, char *tmp, int i)
{
	int	j;

	j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '$'
			&& existing_expand(buffer + i + 1, env, 0, 0) == TRUE)
		{
			tmp = copy_expanded_value(buffer + i + 1, env, tmp, &j);
			i += get_end_of_expansion(buffer + i + 1, env, 0, 0);
		}
		else if (buffer[i] == '$')
		{
			i++;
			while (buffer[i] != '\0' && buffer[i] != ' '
				&& is_it_a_quote(buffer[i]) == FALSE)
				i++;
		}
	}

	return (tmp);
}

char	*get_hd_expansion(t_minishell *m, char *buffer, char **env, int i)
{
	int		len;
	char	*tmp;

	tmp = NULL;
	if (expansion_needed(buffer, i) == FALSE)
		return (buffer);
	len = get_new_heredoc_len(buffer, env, 0, 0);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
	{
		strerror(errno);
		close_heredoc_pipes(m->d_lk);
		m = destroy_all_data(m);
		exit (EXIT_FAILURE);
	}
	tmp = get_new_heredoc(buffer, env, tmp, 0);
	// PD(tmp)
	// ex
	return (tmp);
}

t_dlk_list	*__read_hd__(t_minishell *m, t_dlk_list *dlk, char **env, int eof)
{
	char	*buffer;

	dup2(STDIN_FILENO ,dlk->heredoc_pipe[0]);
	while (eof > 0)
	{
		write(1, ">", 1);
		eof = get_next_line(0, &buffer);
		buffer = get_hd_expansion(m, buffer, env, 0);
		if (ft_strcmp(dlk->limiter, buffer) == TRUE)
		{
			D
			ex
		}
		if (buffer != NULL)
			buffer = expand_heredoc(buffer, 0);
		// write();
	}
	ex
	return (dlk);
}

static t_dlk_list	*__treat_hd__(t_minishell *m, t_dlk_list *dlk, char **env)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1)
			tmp = __read_hd__(m, tmp, env, 1);
		tmp = tmp->next;
	}
	return (dlk);
}

t_dlk_list	*is_there_heredoc(t_minishell *m, t_dlk_list *dlk, char **env)
{
	dlk = __init_heredoc_pipes__(m, dlk, 0);
	dlk = __treat_hd__(m, dlk, env);
	return (dlk);
}

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
	dlk = is_there_heredoc(minishell, dlk, env);
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

void	minishell_core(t_minishell *minishell, int ac, char **av, char **env)
{
	minishell->line = readline("minishell>$ ");
	while (minishell->line != NULL)
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
				minishell = trim_token(minishell, env);
				minishell = treat_data(minishell, env);
				SMDLK
				minishell->line = free_line(minishell->line);
			}
		}
		minishell->line = readline("minishell>$ ");
	}
	(void)ac;
	(void)av;
	destroy_all_data(minishell);
}

/*

Utiliser pas plus d'une variable global et justifier
son utilisation lors de la correction

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
