/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:17:39 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/01 18:34:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	rl_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		signal_handler = 130;
	}
	else if (signum == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 2);
}

void	hd_handler(int signum)
{
	if (signum == SIGINT)
	{
		if (signal_handler == -1)
		{
			write(1, "\n", 1);
			exit (130);
		}
		else
			signal_handler = 130;
	}
	else if (signum == SIGQUIT)
	{
		if (signal_handler == -1)
			ft_putstr_fd("\b\b  \b\b", 2);
	}
}

void	handle_rl_signal()
{
	signal(SIGINT, rl_handler);
	signal(SIGQUIT, rl_handler);
}