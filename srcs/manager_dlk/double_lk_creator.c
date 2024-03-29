/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lk_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:00:26 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/06 15:12:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	get_end_of_quote(char *line, int *ptr_i, int *ptr_j)
{
	int	i;

	i = *ptr_i;
	if (line[i] == SIMPLE_COTE)
	{
		i++;
		while (line[i] != SIMPLE_COTE)
			i++;
	}
	else
	{
		i++;
		while (line[i] != DOUBLE_COTE)
			i++;
	}
	*ptr_i = i;
	*ptr_j = *ptr_i;
}

static char	*cpy_token(char *line, int *p_i, int i, int j)
{
	char	*tmp;

	i = *p_i;
	while (line[i] != '\0' && is_metacharacter(line[i]) == 0 && line[i] != ' ')
	{
		if (is_it_a_quote(line[i]) == 1)
			get_end_of_quote(line, &i, &j);
		i++;
		j++;
	}
	*p_i = i;
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

static t_dlk_list	*get_token(t_dlk_list *dlk, char *line, int *p_i, int i)
{
	i = *p_i;
	i = skip_space(line, i);
	if (line[i] == '\0')
		dlk->only_space = 1;
	if (is_it_a_quote(line[i]) == 1)
	{
		if (line[i] == SIMPLE_COTE)
			dlk->simple_quote++;
		else if (line[i] == DOUBLE_COTE)
			dlk->double_quote++;
		i++;
		dlk = get_coted_token(dlk, line, &i, 1);
	}
	else if (line[i] != '\0' && is_metacharacter(line[i]) == 1)
	{
		if (line[i + 1] == PIPELINE)
			dlk->pipeline_next_to_pipeline = 1;
		dlk = get_metacharacter(dlk, line[i], &i, line);
	}
	else
		dlk->token = cpy_token(line, &i, 0, 0);
	i = skip_space(line, i);
	*p_i = i;
	return (dlk);
}

static t_dlk_list	*get_next_tokens(t_dlk_list *dlk, char *line, int i)
{
	t_dlk_list	*tmp;
	t_dlk_list	*new;

	new = NULL;
	while (line[i] != '\0')
	{
		new = (t_dlk_list *)malloc(sizeof(t_dlk_list));
		if (new == NULL)
			return (NULL);
		new->next = NULL;
		new->only_space = 0;
		new = init_dlk_metacharacter(new);
		new = get_token(new, line, &i, 0);
		if (new->is_metacharacter == 0 && new->token == NULL)
			return (NULL);
		tmp = dlk;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->previous = tmp;
	}
	return (dlk);
}

t_dlk_list	*double_lk_creator(t_minishell *minishell, char *line, int i)
{
	t_dlk_list	*dlk;

	dlk = (t_dlk_list *)malloc(sizeof(t_dlk_list));
	if (dlk == NULL)
		init_dlk_creator_failed(minishell);
	dlk->previous = NULL;
	dlk->only_space = 0;
	dlk = init_dlk_metacharacter(dlk);
	dlk = get_token(dlk, line, &i, 0);
	if (dlk->is_metacharacter == 0 && dlk->token == NULL)
		init_dlk_token_failed(minishell);
	if (line[i] != '\0')
		dlk = get_next_tokens(dlk, line, i);
	if (dlk->is_metacharacter == 0 && dlk == NULL)
		init_dlk_token_failed(minishell);
	return (dlk);
}
