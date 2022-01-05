/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:26:51 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 11:52:40 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	count_args(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	return (i);
}

static void	arg_is_ascii(t_minishell *m, char *arg)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	ft_putstr_fd("bash: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	m = destroy_cmd_data(m);
	m = destroy_data(m);
	m = destroy_all_data(m);
	exit(2);
}

static void	arg_is_num(t_minishell *m, char *str_nbr)
{
	int	nbr;

	nbr = ft_atoi(str_nbr);
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	m = destroy_cmd_data(m);
	m = destroy_data(m);
	m = destroy_all_data(m);
	exit(nbr);
}

static void	no_args(t_minishell *m)
{
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	m = destroy_cmd_data(m);
	m = destroy_data(m);
	m = destroy_all_data(m);
	exit(0);
}

void	exit_builtin(t_minishell *m, t_cmd *cmd)
{
	int			i;
	int			args_nbr;

	args_nbr = count_args(cmd->cmd);
	if (args_nbr == 1)
		no_args(m);
	else if (args_nbr > 2)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		ft_putstr_fd("bash: exit: too many arguments\n", STDERR_FILENO);
		signal_handler = 1;
	}
	else if (args_nbr == 2)
	{
		i = 0;
		while (cmd->cmd[1][i] != '\0')
		{
			if (ft_isdigit(cmd->cmd[1][i]) == FALSE)
				arg_is_ascii(m, cmd->cmd[1]);
			i++;
		}
		arg_is_num(m, cmd->cmd[1]);
	}
}
