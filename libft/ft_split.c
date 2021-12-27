/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:46:00 by oozsertt          #+#    #+#             */
/*   Updated: 2021/12/26 18:50:20 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>

static size_t	get_words_nbr(char *str, char c)
{
	int	i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\0' && str[i] != c)
		{
			size++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (size);
}

static char	**malloc_tab(char **finaltab, char *str, char c)
{
	int	i;
	int	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\0' && str[i] != c)
		{
			while (str[i] != '\0' && str[i++] != c)
				len++;
			finaltab[j] = (char *)malloc(sizeof(char) * (len + 1));
			if (finaltab[j] == NULL)
				return (NULL);
			finaltab[j][len] = '\0';
			len = 0;
			j++;
		}
		else
			i++;
	}
	return (finaltab);
}

static char	**fill_tab(char **final_tab, char *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[j] != '\0')
	{
		if (str[j] != '\0' && str[j] != c)
		{
			while (str[j] != '\0' && str[j] != c)
			{
				final_tab[i][k] = str[j];
				j++;
				k++;
			}
			i++;
			k = 0;
		}
		else
			j++;
	}
	return (final_tab);
}

char	**ft_split(char *s, char c)
{
	char		**finaltab;
	size_t		finaltab_len;

	if (s == NULL)
		return (NULL);
	finaltab_len = get_words_nbr(s, c);
	finaltab = (char **)malloc(sizeof(char *) * (finaltab_len + 1));
	if (finaltab == NULL)
		return (NULL);
	finaltab[finaltab_len] = NULL;
	finaltab = malloc_tab(finaltab, s, c);
	finaltab = fill_tab(finaltab, s, c);
	return (finaltab);
}
