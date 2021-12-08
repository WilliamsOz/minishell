/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:42:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 15:23:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char		*__get_final_token__(t_trim *trim, int i, int j, int len)
{
	char	*token;

	len = ft_strlen(trim->before_quote) + ft_strlen(trim->between_quote)
		+ ft_strlen(trim->after_quote);
	token = (char *)malloc(sizeof(char) * (len + 1));
	if (token == NULL)
		return (NULL);
	token[len] = '\0';
	while (trim->before_quote != NULL && trim->before_quote[i] != '\0')
		token[j++] = trim->before_quote[i++];
	i = 0;
	while (trim->between_quote != NULL && trim->between_quote[i] != '\0')
		token[j++] = trim->between_quote[i++];
	i = 0;
	while (trim->after_quote != NULL && trim->after_quote[i] != '\0')
		token[j++] = trim->after_quote[i++];
	return (token);
}

char	*get_before_quote(t_trim *trim, char *token, int i)
{
	while (token[i] != '\0' &&
		token[i] != SIMPLE_COTE && token[i] != DOUBLE_COTE)
		i++;
	trim->before_quote = (char *)malloc(sizeof(char) * (i + 1));


	return (trim->before_quote);
}

int	move_untill_token_cotes(char *token, int i)
{
	while (token[i] != '\0' &&
		token[i] != SIMPLE_COTE && token[i] != DOUBLE_COTE)
		i++;
	return (i);
}

int	move_untill_token_end_cote(char *token, int i)
{
	while (token[i] != '\0' &&
		token[i - 1] != SIMPLE_COTE && token[i - 1] != DOUBLE_COTE)
		i++;
	return (i);
}

static char		*__trim_token__(t_minishell *minishell, char *token, int i)
{
	t_trim	*trim;

	trim = init_trim();
	if (token[i] != SIMPLE_COTE && token[i] != DOUBLE_COTE)
	{
		trim->before_quote = get_before_quote(trim, token, &i);
		if (trim->before_quote == NULL)
			trim_malloc_failed(minishell, trim);
	}
	if (token[i] == SIMPLE_COTE || token[i] == DOUBLE_COTE)
	{
		trim->between_quote = get_between_quote(trim, token, &i);
		if (trim->between_quote == NULL)
			trim_malloc_failed(minishell, trim);
	}
	if (token[i] != '\0')
	{
		trim->after_quote = get_after_quote(trim, token, &i);
		if (trim->after_quote == NULL)
			trim_malloc_failed(minishell, trim);
	}
	free(token);
	token = __get_final_token__(trim, 0, 0, 0);
	destroy_trim(trim);
	PS(token)
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
			{
				tmp->token = __trim_token__(minishell, tmp->token, 0);
				if (tmp->token == NULL)
				{
					strerror(errno);
					minishell = destroy_all_data(minishell);
					exit (EXIT_FAILURE);
				}
			}
		}
		tmp = tmp->next;
	}
	return (minishell);
}
