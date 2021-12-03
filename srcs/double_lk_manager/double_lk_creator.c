/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lk_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:00:26 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/03 19:21:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


static t_dlk_list	*get_token(t_dlk_list *dlk, char *line, int *ptr_i, int i)
{
	i = *ptr_i;
	i = skip_space(line, i);
	if (line[i] != '\0' && is_metacharacter(line[i] == 1))
		dlk = get_metacharacter(dlk, line[i], &ptr_i);
	/*
	faire une fct qui va catch la string meme si ya des cote
	attention, si ya des cote, la fct va catch avant/pendant/apres
	jusqu'a un espace ou un metacaractere
	*/
	i = skip_space(line, i);
	*ptr_i = i;
	return (dlk);
}

t_dlk_list	*get_next_tokens(t_minishell *minishell, char *line, int i)
{
	t_dlk_list	*tmp;
	t_dlk_list	*new;

	new = NULL;
	while (line[i] != '\0')
	{
		new = (t_dlk_list *)malloc(sizeof(t_dlk_list));
		if (new == NULL)
			init_dlk_token_failed(minishell);
		new = init_dlk_metacharacter(new);
		new = get_token(new, line, &i, 0);
		tmp = minishell->d_lk;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->previous = tmp;
		tmp->next = new;
	}
	return (minishell->d_lk);
}

t_dlk_list	*double_lk_creator(t_minishell *minishell, char *line, int i)
{
	t_dlk_list	*dlk;

	dlk = (t_dlk_list *)malloc(sizeof(t_dlk_list));
	if (dlk == NULL)
		init_dlk_creator_failed(minishell);
	dlk->previous = NULL;
	dlk = init_dlk_metacharacter(dlk);
	dlk = get_token(dlk, line, &i, 0);
	PS(dlk->token)
	if (dlk->token == NULL)
		init_dlk_token_failed(minishell);
	// dlk = get_next_tokens(minishell, line, i);
	return (dlk);
}
