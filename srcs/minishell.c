/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 16:55:43 by wiozsert         ###   ########.fr       */
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
			minishell = check_tokens_errors(minishell);
			if (minishell->line != NULL)
			{
				SMDLK
				minishell = trim_token(minishell, env);
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
Le shell :

_OK_ Ne doit pas interpreter des cotes simple ou double pas fermer
_OK_ Ne doit pas interpreter des caracteres special non specifies comme \ ou ;
_OK_ Afficher un promp lorsqu'il attend une nouvelle commande
_OK_ Avoir un historique de travail fonctionnel



Utiliser pas plus d'une variable global et justifier
son utilisation lors de la correction (singleton? Cf kaye)

Chercher et lancer le bonne executable (base sur la variable PATH????? ou
en utilisant le chemin relatif ou absolu)

’ inhibe toute interprétation d’une séquence de caractères.

" inhibe toute interprétation d'une séquence de caractères à l'exception de $.

Redirection :
< doit redigirer l'entree
> doit rediriger la sortie en mode TRUNC
<< read depuis une pipe
>> doit rediriger la sortie en mode APPEND

Pipes | :
La sortie de chaque commande est connecter via
pipe a l'entree de la prochaine commande

Les variables d'environement ($ suivi des caracteres)
doit etre expandu a leur valeur

$? doit etre receptionne et renvoyer le
dernier status de la derniere commande

Ctrl-C && Ctrl-D && ctrl-\ doivent fonctionner comme
dans le bash (signaux)

Lorsqu'il est interactif :
Ctrl-C affiche un nouveau promt dans une nouvelle ligne
Ctrl-D exit le shell
Ctrl-\ ne fait rien


1_recuperer les token, attention au quote

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

//pour les built in pour setenv unsetenv (export et unset)
//regarder les fonctions qui existe
//et les suivre pour les refaire