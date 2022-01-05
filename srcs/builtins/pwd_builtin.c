/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:10:03 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 11:57:21 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	find_pwd(char *var, char *pwd_header)
{
	int	i;

	i = 0;
	while (pwd_header[i] != '\0')
	{
		if (var[i] != pwd_header[i] && var[i] != '\0')
			return (FALSE);
		i++;
	}
	if (pwd_header[i] == '\0')
		return (TRUE);
	else
		return (FALSE);
}

static int	is_flag_error(t_cmd *cmd)
{
	char	*flag;

	flag = cmd->cmd[1];
	if (flag != NULL && flag[0] == '-')
	{
		if (flag[1] == 'L' || flag[1] == 'P')
			ft_putstr_fd("pwd does not support any option\n", cmd->output);
		else if (flag[1] != 'L' && flag[1] != 'P')
		{
			ft_putstr_fd("bash: pwd: -d: invalid option\n", cmd->output);
			ft_putstr_fd("pwd: usage: pwd [-LP]\n", cmd->output);
		}
		return (TRUE);
	}
	return (FALSE);
}

void	pwd_builtin(t_cmd *cmd, t_env *env)
{
	int		i;
	t_env	*tmp;

	if (is_flag_error(cmd) == TRUE)
		g_signal_handler = 2;
	else
	{
		tmp = env;
		while (env != NULL)
		{
			if (find_pwd(env->var, "PWD=") == TRUE)
			{
				i = 0;
				while (env->var[i] != '=')
					i++;
				ft_putstr_fd(&env->var[++i], cmd->output);
				ft_putstr_fd("\n", cmd->output);
			}
			env = env->next;
		}
		env = tmp;
		g_signal_handler = 0;
	}
}
