/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:42:59 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 17:01:01 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*get_null_token(t_minishell *minishell)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char));
	if (dest == NULL)
	{
		strerror(errno);
		minishell = destroy_all_data(minishell);
		exit (errno);
	}
	dest[0] = '\0';
	return (dest);
}

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
		tmp = get_null_token(m);
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
		exit (errno);
	}
	if (ind != -1)
	{
		free(token);
		token = NULL;
	}
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
