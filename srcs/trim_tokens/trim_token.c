/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:42:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/13 12:57:44 by user42           ###   ########.fr       */
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

static char	*__trim__(t_minishell *minishell, char *token, int i, char **env)
{
	char	*tmp;

	tmp = get_new_token(token, &i, env);
	if (tmp == NULL)
	{
		strerror(errno);
		minishell = destroy_all_data(minishell);
		exit (EXIT_FAILURE);
	}
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
				tmp->token = __trim__(minishell, tmp->token, 0, env);
		}
		tmp = tmp->next;
	}
	return (minishell);
}
