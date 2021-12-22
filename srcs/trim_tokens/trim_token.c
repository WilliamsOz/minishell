/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:42:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/22 20:05:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*get_new_token(char *token, int *ptr_i, char **env)
{
	char	*tmp;
	int		i;
	int		len;

	i = *ptr_i;
	tmp = NULL;
	len = get_final_len(token, env, i, 0);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	tmp = get_trimed_token(token, tmp, env, &i);
	*ptr_i = i;
	return (tmp);
}

char	*trim(t_minishell *minishell, char *token, int i, char **env)
{
	char	*tmp;
	int		ind;

	ind = 0;
	if (i++ == -1)
		ind = -1;
	else
		i--;
	tmp = get_new_token(token, &i, env);
	if (tmp == NULL)
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

t_minishell	*trim_token(t_minishell *minishell, char **env)
{
	t_dlk_list	*tmp;

	tmp = minishell->d_lk;
	while (tmp != NULL)
	{
		if (tmp->token != NULL)
		{
			if (need_to_be_trim(tmp->token, 0) == TRUE)
				tmp->token = trim(minishell, tmp->token, 0, env);
		}
		tmp = tmp->next;
	}
	return (minishell);
}
