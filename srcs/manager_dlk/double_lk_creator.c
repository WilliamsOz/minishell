/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lk_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:00:26 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/07 17:32:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//modifier la fonction : cc' cc"cc'""cc<"c" doit recuperer cc' cc"cc'""cc<"c"
//si aucune cote ouvert elle split avec les espace et les metacaractere
//si cote ouverte, elle recupere tout ce quil y a jusqua la fin de la cote
//puis si pas de nouvelle cote et pas despace et pas de metacaractere
//elle continue a recuperer

static void			__get_end_of_quote__(char *line, int *ptr_i, int *ptr_j)
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

static char			*_cpy_token_(char *line, int *p_i, int i, int j)
{
	char	*tmp;

	i = *p_i;
	while (line[i] != '\0' && is_metacharacter(line[i]) == 0 && line[i] != ' ')
	{
		if (is_it_a_quote(line[i]) == 1)
			__get_end_of_quote__(line, &i, &j);
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

static t_dlk_list	*__get_token__(t_dlk_list *dlk, char *str, int *p_i, int i)
{
	i = *p_i;
	i = skip_space(str, i);
	if (is_it_a_quote(str[i]) == 1)
	{
		if (str[i] == SIMPLE_COTE)
			dlk->simple_quote++;
		else if (str[i] == DOUBLE_COTE)
			dlk->double_quote++;
		i++;
		dlk = get_coted_token(dlk, str, &i, 1);
	}
	else if (str[i] != '\0' && is_metacharacter(str[i]) == 1)
	{
		if (str[i + 1] == PIPELINE)
			dlk->pipeline_next_to_pipeline = 1;
		dlk = get_metacharacter(dlk, str[i], &i, str);
	}
	else
		dlk->token = _cpy_token_(str, &i, 0, 0);
	i = skip_space(str, i);
	*p_i = i;
	return (dlk);
}

static t_dlk_list	*__get_next_tokens__(t_dlk_list *dlk, char *line, int i)
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
		new = init_dlk_metacharacter(new);
		new = __get_token__(new, line, &i, 0);
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
	dlk = init_dlk_metacharacter(dlk);
	dlk = __get_token__(dlk, line, &i, 0);
	if (dlk->is_metacharacter == 0 && dlk->token == NULL)
		init_dlk_token_failed(minishell);
	dlk = __get_next_tokens__(dlk, line, i);
	if (dlk->is_metacharacter == 0 && dlk == NULL)
		init_dlk_token_failed(minishell);
	return (dlk);
}
