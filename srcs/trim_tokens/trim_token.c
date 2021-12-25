/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:42:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/25 13:23:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*get_new_token(t_minishell *m, char *token, int *ptr_i)
{
	char	*tmp;
	int		i;
	int		len;

	i = *ptr_i;
	tmp = NULL;
	len = get_final_len(token, m->env, i, 0);
	if (len == 0)
	{
		tmp = NULL;
		return (tmp);
	}
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	tmp = get_trimed_token(token, tmp, m->env, &i);
	*ptr_i = i;
	return (tmp);
}

char	*trim(t_minishell *minishell, char *token, int i)
{
	char	*tmp;
	int		ind;

	ind = 0;
	if (i++ == -1)
		ind = -1;
	else
		i--;
	tmp = get_new_token(minishell, token, &i);
	if (tmp == NULL && errno != 0)
	{
		strerror(errno);
		minishell = destroy_all_data(minishell);
		exit (EXIT_FAILURE);
	}
	if (ind != -1)
		free(token);
	token = tmp;
	return (token);
}

t_minishell	*trim_token(t_minishell *minishell)
{
	t_dlk_list	*tmp;

	tmp = minishell->d_lk;
	while (tmp != NULL)
	{
		if (tmp->token != NULL)
		{
			if (need_to_be_trim(tmp->token, 0) == TRUE)
				tmp->token = trim(minishell, tmp->token, 0);
		}
		tmp = tmp->next;
	}
	return (minishell);
}
