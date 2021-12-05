/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/05 15:17:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    show_dlk(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		printf("\n");
		if (tmp->token != NULL)
		{
			BLUECLR
			printf("Token :\n");
			PS(tmp->token)
			printf("\n");
			STOPCLR
		}
		else if (tmp->is_metacharacter == 1)
		{
			YELLOWCLR
			if (tmp->pipeline == 1)
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

t_minishell	*destroy_all_data(t_minishell *minishell)
{
	if (minishell->parsing_err != NULL)
		parsing_err_destroyer(minishell->parsing_err);
	if (minishell->d_lk != NULL)
		double_lk_destroyer(minishell->d_lk);
	if (minishell != NULL)
		minishell_destroyer(minishell);
	return (minishell);
}

void	minishell_core(t_minishell *minishell, int ac, char **av, char **env)
{
	minishell->line = readline("minishell>$ ");
	while (minishell->line != NULL)
	{
		add_history(minishell->line);
		minishell = are_quotes_closed(minishell);
		if (minishell->line != NULL && minishell->line[0] != '\0')
		{
			minishell->d_lk = double_lk_creator(minishell,
				minishell->line, 0);
			SMDLK
			minishell = check_tokens_errors(minishell);
			if (minishell->line != NULL)
				minishell->line = free_line(minishell->line);
		}
		minishell->line = readline("minishell>$ ");
	}
	(void)ac;
	(void)av;
	(void)env;
	destroy_all_data(minishell);
}

/*
Le shell :

_OK_ Ne doit pas interpreter des cotes simple ou double pas fermer
_OK_ Ne doit pas interpreter des caracteres special non specifies comme \ ou ;

Utiliser pas plus d'une variable global et justifier
son utilisation lors de la correction (singleton? Cf kaye)

_OK_ Afficher un promp lorsqu'il attend une nouvelle commande

Avoir un historique de travail fonctionnel

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
