/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:59:31 by oozsertt          #+#    #+#             */
/*   Updated: 2021/12/28 17:41:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	fill_finalstr(char *finalstr, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 != NULL && s1[j] != '\0')
	{
		finalstr[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
	{
		finalstr[i] = s2[j];
		i++;
		j++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*finalstr;
	size_t	finalstr_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		finalstr_len = ft_strlen(s2);
	else if (s2 == NULL)
		finalstr_len = ft_strlen(s1);
	else
		finalstr_len = ft_strlen(s1) + ft_strlen(s2);
	finalstr = (char *)malloc(sizeof(char) * (finalstr_len + 1));
	if (finalstr == NULL)
		return (NULL);
	finalstr[finalstr_len] = '\0';
	fill_finalstr(finalstr, s1, s2);
	return (finalstr);
}
