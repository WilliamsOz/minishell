/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_called.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:28:31 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 14:29:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	eof_called(t_minishell *minishell, t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	int			count;

	count = 0;
	tmp = minishell->d_lk;
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1)
			count += tmp->hd_line_count;
		tmp = tmp->next;
	}
	ft_putstr_fd(" bash: warning: here-document at line ", 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(dlk->limiter, 2);
	ft_putstr_fd("')\n", 2);
}
