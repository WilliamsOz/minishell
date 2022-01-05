/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:49:58 by user42            #+#    #+#             */
/*   Updated: 2022/01/05 11:26:30 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	mall_var_failed(t_minishell *m, t_env *keep)
{
	t_env	*tmp;

	strerror(errno);
	tmp = m->env;
	while (tmp != keep)
	{
		free(tmp->var);
		tmp = tmp->next;
	}
	tmp = m->env;
	while (tmp != NULL)
	{
		keep = tmp->next;
		free(tmp);
		tmp = keep;
	}
	m = destroy_all_data(m);
	exit (errno);
}

static char	*cpy_var(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

t_env	*create_var(t_minishell *m, char **env, int i, int j)
{
	t_env	*tmp;

	tmp = m->env;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
			j++;
		tmp->var = (char *)malloc(sizeof(char) * (j + 1));
		if (tmp->var == NULL)
			mall_var_failed(m, tmp);
		tmp->var[j] = '\0';
		tmp->var = cpy_var(env[i], tmp->var);
		i++;
		tmp = tmp->next;
	}
	return (m->env);
}
