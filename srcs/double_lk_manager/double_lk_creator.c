/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lk_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:00:26 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/03 23:25:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char			*copy_token(char *line, int *ptr_i, int i, int j)
{
	char	*tmp;

	i = *ptr_i;
	while (line[i] != '\0' && line[i] != LOWER_RAFTER &&
			line[i] != UPPER_RAFTER && line[i] != PIPELINE)
	{
		i++;
		j++;
	}
	*ptr_i = i;
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[j] = '\0';
	while (--j >= 0)
	{
		i--;
		tmp[j] = line[i];
	}
	return (tmp);
}

static t_dlk_list	*get_token(t_dlk_list *dlk, char *line, int *ptr_i, int i)
{
	i = *ptr_i;
	i = skip_space(line, i);
	if (line[i] != '\0' && is_metacharacter(line[i]) == 1)
		dlk = get_metacharacter(dlk, line[i], &i);
	else
	{
		dlk->token = copy_token(line, &i, 0, 0);
		if (dlk->token == NULL)
			return (NULL);
	}
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
		if (new->is_metacharacter == 0 && new->token == NULL)
			init_dlk_token_failed(minishell);
		tmp = minishell->d_lk;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->previous = tmp;
		tmp->next = new;
		new->next = NULL;
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
	minishell->d_lk = init_dlk_metacharacter(dlk);
	dlk = get_token(dlk, line, &i, 0);
	if (dlk->token == NULL)
		init_dlk_token_failed(minishell);
	dlk = get_next_tokens(minishell, line, i);
	return (dlk);
}
