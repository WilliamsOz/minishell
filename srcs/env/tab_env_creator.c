/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_env_creator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:35:27 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/30 12:57:21 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	get_env_len(t_env *env)
{
	t_env	*tmp;
	int		i;
	int		len;

	tmp = env;
	len = 0;
	while (tmp != NULL)
	{
		while (tmp->var[i] != '\0')
		{
			i++;
			len++;
		}
		i = 0;
		tmp = tmp->next;
	}
	return (len);
}

static char	**init_tab_env(t_minishell *m)
{
	int	len;

	len = get_env_len(m->env);
	m->tab_env = (char **)malloc(sizeof(char *) * (len + 1));
	if (len != 0 && m->tab_env == NULL)
		mall_tab_env_failed(m);
	m->tab_env[len] = NULL;
	return (m->tab_env);
}

static char	*cpy_env(char *src, char *dest, int i)
{
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	tab_env_destructor(t_minishell *m)
{
	int	i;

	i = 0;
	while (m->tab_env[i] != NULL)
	{
		free(m->tab_env[i]);
		i++;
	}
	free(m->tab_env);
}

t_minishell	*tab_env_creator(t_minishell *m)
{
	t_env	*tmp;
	int		i;
	int		len;

	m->tab_env = init_tab_env(m);
	i = 0;
	tmp = m->env;
	while (tmp != NULL)
	{
		len = ft_strlen(tmp->var);
		m->tab_env[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (m->tab_env[i] == NULL)
			mall_str_tab_env_failed(m);
		m->tab_env[i] = cpy_env(tmp->var, m->tab_env[i], 0);
		i++;
		tmp = tmp->next;
	}
	return (m);
}
