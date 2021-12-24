/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_eof_called.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:16:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/24 18:43:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	minishell_eof_called(void)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	write(1, "exit\n", 5);
}
