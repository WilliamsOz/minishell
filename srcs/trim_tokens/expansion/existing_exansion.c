/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing_exansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:15:42 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 18:05:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	still_env_key(char c)
{
	if (c >= 'a' && c <= 'z')
		return (TRUE);
	else if (c >= 'A' && c <= 'Z')
		return (TRUE);
	else if (c >= '0' && c <= '9')
		return (TRUE);
	else if (c == '_')
		return (TRUE);
	return (FALSE);
}

int	existing_expand(char *token, t_env *env, int i)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		i = 0;
		if (tmp->var[i] == token[i] && i == 0)
		{
			while (tmp->var[i] != '\0' && token[i] != '\0'
				&& tmp->var[i] == token[i])
				i++;
			if (tmp->var[i] == '=' && still_env_key(token[i]) == TRUE)
				return (FALSE);
			else if (tmp->var[i] == '=')
				return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}
