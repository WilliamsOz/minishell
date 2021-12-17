/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_failed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:14:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/17 19:13:24 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	pipe_failed(t_minishell *minishell)
{
	strerror(errno);
	close_heredoc_pipes(minishell->d_lk);
	minishell = destroy_all_data(minishell);
	exit (EXIT_FAILURE);
}
