/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:41:58 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/03 17:31:37 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_minishell	*init_double_linked_list(t_minishell *minishell, char *line)
{
	

	return (minishell);
}

void	minishell_core(t_minishell *minishell, int ac, char **av, char **env)
{
	minishell->line = readline("minishell> ");
	while (minishell->line != NULL)
	{
		minishell = check_interpretation_errors(minishell);
		minishell->dlk_minishell = init_double_linked_list(minishell,
			minishell->line);
		if (minishell->line != NULL)
			minishell->line = free_line(minishell->line);
		if (minishell->parsing_err->exit_called == 0)
			minishell->line = readline("minishell> ");
	}
	(void)ac;
	(void)av;
	(void)env;
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
