/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:10:03 by oozsertt          #+#    #+#             */
/*   Updated: 2021/12/26 19:55:34 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	pwd_builtin(t_env *env)
{
	int		i;
	t_env	*tmp;

	tmp = env;
	while (env != NULL)
	{
		if (ft_strcmp(env->var, "PWD=") == 1)
		{
			i = 0;
			while (env->var[i] != '=')
				i++;
			ft_putstr_fd(&env->var[i], STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		env = env->next;
	}
	env = tmp;
}
