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

// static int	count_args(t_dlk_list *dlk)
// {
// 	int	count;

// 	count = 0;
// 	while (dlk != NULL)
// 	{
// 		count++;
// 		dlk = dlk->next;
// 	}
// 	return (count);
// }

// static void	arg_is_ascii(char *arg)
// {
// 	ft_putstr_fd("exit\n", STDOUT_FILENO);
// 	ft_putstr_fd("bash: exit: ", STDERR_FILENO);
// 	ft_putstr_fd(arg, STDERR_FILENO);
// 	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
// 	exit(2);// TO FREE + check if signal handler is 0
// }

// static void	arg_is_num(char *str_nbr)
// {
// 	int	nbr;
	
// 	nbr = ft_atoi(str_nbr);
// 	ft_putstr_fd("exit\n", STDOUT_FILENO);
// 	exit(nbr);// TO FREE + check if signal handler is 0
// }

// static void	no_args()
// {
// 	ft_putstr_fd("exit\n", STDOUT_FILENO);
// 	exit(0); // TO FREE + check if signal handler is 0
// }

// void	exit_builtin(t_dlk_list *dlk)
// {
// 	int			i;
// 	t_dlk_list *tmp;
// 	int			args_nbr;

// 	tmp = dlk;
// 	args_nbr = count_args(dlk);
// 	if (args_nbr == 0)
// 		no_args();
// 	else if (args_nbr > 1)
// 	{
// 		ft_putstr_fd("exit\nbash: exit: too many arguments\n", STDERR_FILENO);
// 		signal_handler = 1;
// 	}
// 	else if (args_nbr == 1)
// 	{
// 		i = 0;
// 		while (dlk->token[i] != '\0')
// 		{
// 			if (ft_isdigit(dlk->token[i]) == FALSE)
// 				arg_is_ascii(dlk->token);
// 			i++;
// 		}
// 		arg_is_num(dlk->token);
// 	}
// }
