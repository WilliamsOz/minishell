/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:34:18 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/01 18:34:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	cmd_handlers(int signum)
{
	if (SIGQUIT == signum)
	{
		if (signal_handler == -1)
		{
			ft_putstr_fd("Quit (core dumped)\n", 2);
			exit (errno);
		}
		else
			signal_handler = 131;
	}
}
