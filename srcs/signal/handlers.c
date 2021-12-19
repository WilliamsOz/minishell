/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:17:39 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/19 14:55:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// void	catch_sigquit()
// {
// 	pid_t	pid;

// 	pid = fork();
// 	// if (pid == -1)
// 		//error
// 	if (pid == 0)
// 	{
// 		while (1);
// 	}
// 	else
// 	{
// 		D
// 		kill(pid, SIGQUIT);
// 	}
// }

void	handle_rl_sigint(int signum)
{
	// if (signum == SIGINT)
	// {
	// 	write(1, "\n", 1);
	// 	rl_on_new_line();
	// 	rl_replace_line("", 0);
	// 	rl_redisplay();
	// 	signal_handler = 130;
	// }
	if (signum == SIGQUIT)
	{
		signal_handler = 0;
	}
}

void	handle_hd_sigint(int signum)
{
	if (signum == SIGINT)
		signal_handler = 130;
}
