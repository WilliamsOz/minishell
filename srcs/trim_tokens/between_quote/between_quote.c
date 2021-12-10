/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:55:27 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/10 19:35:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*ft_strjoin(char *first, char *last, int i, int j)
{
	char	*dest;
	int		len;

	len = ft_strlen(first) + ft_strlen(last);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	while (first[i] != '\0')
	{
		dest[i] = first[i];
		i++;
	}
	while (last[j] != '\0')
	{
		dest[i] = last[j];
		i++;
		j++;
	}
	free(first);
	free(last);
	return (dest);
}


char	*inside_simp_quote(char *token, char *tmp, int *ptr_i, int *ptr_j)
{
	int	i;
	int	j;

	*ptr_i += 1;
	i = *ptr_i;
	j = *ptr_j;
	while (token[i] != SIMPLE_COTE)
	{
		tmp[j] = token[i];
		i++;
		j++;
	}
	i++;
	*ptr_i = i;
	*ptr_j = j;
	return (tmp);
}

char	*bw_get_final_token(char *token, char *tmp, char **env, int *ptr_i)
{
	int	i;
	int	j;

	i = *ptr_i;
	j = 0;
	(void)env;
	if (token[i] == SIMPLE_COTE)
		tmp = inside_simp_quote(token, tmp, &i, &j);
	// else if (token[i] == DOUBLE_COTE)			//faire cette fonction avec lexpansion
	// 	tmp = inside_double_cote(token, tmp, &i, &j);
	// else if (token[i] == '$')					//faire l'expansion simple
	// 	tmp = get_expansion(token, tmp, &i, &j);
	// else
		// tmp = cpy_token			//copier normalement jusqu'a un metachar '\0' ou $
	*ptr_i = i;
	return (tmp);
}

char	*get_between_quote(char *token, int *ptr_i, char **env)
{
	char	*tmp;
	char	*keep;
	int		i;
	int		len;

	i = *ptr_i;
	tmp = NULL;
	while (quotes_remaining(token + i, 0) == TRUE)
	{
		keep = tmp;
		len = get_between_len(token + i, env, 0, i);
		tmp = (char *)malloc(sizeof(char) * (len + 1));
		if (tmp == NULL)
			return (NULL);
		tmp[len] = '\0';
		tmp = bw_get_final_token(token, tmp, env, &i);
		if (keep != NULL)
		{
			tmp = ft_strjoin(keep, tmp, 0, 0);
			if (tmp == NULL)
				return (NULL);
		}
	}
	*ptr_i = i;
	return (tmp);
}
