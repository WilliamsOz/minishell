/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eof_called.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:28:31 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/25 13:00:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*eof_called(t_minishell *minishell, t_dlk_list *dlk)
{
	ft_putstr_fd("bash: warning: here-document", 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(dlk->limiter, 2);
	ft_putstr_fd("')\n", 2);
	return (minishell);
}
