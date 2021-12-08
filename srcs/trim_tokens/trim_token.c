/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:42:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 17:32:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*__get_final_token__(t_trim *trim, int i, int j, int len)
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

static char	*__trim__(t_minishell *minishell, char *token, int i, char **env)
{
	t_trim	*trim;

	(void)env;
	trim = init_trim(minishell);
	if (token[i] != SIMPLE_COTE && token[i] != DOUBLE_COTE)
	{
		trim->before_quote = before_quote(trim, token, &i, env);
		if (trim->before_quote == NULL)
			trim_malloc_failed(minishell, trim);
	}
	// if (token[i] == SIMPLE_COTE || token[i] == DOUBLE_COTE)
	// {
	// 	trim->between_quote = get_between_quote(trim, token, &i, env);
	// 	if (trim->between_quote == NULL)
	// 		trim_malloc_failed(minishell, trim);
	// }
	// if (token[i] != '\0')
	// {
	// 	trim->after_quote = get_after_quote(trim, token, &i, 0);
	// 	if (trim->after_quote == NULL)
	// 		trim_malloc_failed(minishell, trim);
	// }
	free(token);
	token = __get_final_token__(trim, 0, 0, 0);
	destroy_trim(trim);
	PS(token)
	ex
	return (token);
}

t_minishell	*trim_token(t_minishell *minishell, char **env)
{
	t_dlk_list	*tmp;

	tmp = minishell->d_lk;
	(void)env;
	while (tmp != NULL)
	{
		if (tmp->token != NULL)
		{
			if (need_to_be_trim(tmp->token, 0) == TRUE)
			{
				tmp->token = __trim__(minishell, tmp->token, 0, env);
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
