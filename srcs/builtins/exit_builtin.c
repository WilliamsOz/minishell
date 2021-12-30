// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   exit_builtin.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/12/26 20:26:51 by oozsertt          #+#    #+#             */
// /*   Updated: 2021/12/27 15:39:05 by oozsertt         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../inc/minishell.h"

//There are four types of exit, each write exit in terminal:
//exit : exit and set exit status to 0;
//exit (num) : exit and set exit status to num
//exit (num alpha) : exit and set exit status to 2 + a error message
//exit (num) (num) (num) : doesn't exit and set exit status to 1 + a error message

static int	count_args(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	return (i);
}

static void	arg_is_ascii(t_cmd *cmd, char *arg)
{
	ft_putstr_fd("exit\n", cmd->output);
	ft_putstr_fd("bash: exit: ", cmd->output);
	ft_putstr_fd(arg, cmd->output);
	ft_putstr_fd(": numeric argument required\n", cmd->output);
	exit(2);// TO FREE + check if signal handler is 0
}

static void	arg_is_num(t_cmd *cmd, char *str_nbr)
{
	int	nbr;
	
	nbr = ft_atoi(str_nbr);
	ft_putstr_fd("exit\n", cmd->output);
	exit(nbr);// TO FREE + check if signal handler is 0
}

static void	no_args(t_cmd *cmd)
{
	ft_putstr_fd("exit\n", cmd->output);
	exit(0); // TO FREE + check if signal handler is 0
}

void	exit_builtin(t_cmd *cmd)
{
	int			i;
	int			args_nbr;

	args_nbr = count_args(cmd->cmd);
	if (args_nbr == 1)
		no_args(cmd);
	else if (args_nbr > 2)
	{
		ft_putstr_fd("exit\nbash: exit: too many arguments\n", cmd->output);
		signal_handler = 1;
	}
	else if (args_nbr == 2)
	{
		i = 0;
		while (cmd->cmd[1][i] != '\0')
		{
			if (ft_isdigit(cmd->cmd[1][i]) == FALSE)
				arg_is_ascii(cmd, cmd->cmd[1]);
			i++;
		}
		arg_is_num(cmd, cmd->cmd[1]);
	}
}
