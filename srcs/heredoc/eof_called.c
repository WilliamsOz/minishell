/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_called.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:28:31 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 18:36:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*eof_called(t_minishell *minishell, t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	int			count;

	count = 1;
	tmp = minishell->d_lk;
	while (tmp != NULL)
	{
		if (tmp->hd_line_count == 1)
			count++;
		tmp = tmp->next;
	}
	ft_putstr_fd("bash: warning: here-document at line ", 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(dlk->limiter, 2);
	ft_putstr_fd("')\n", 2);
	return (minishell);
}
