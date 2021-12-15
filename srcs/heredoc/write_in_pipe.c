/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:56:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/15 12:42:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	write_hd_inside_pipe(t_dlk_list *dlk, char *buffer, int *ptr_count)
{
	write(dlk->heredoc_pipe[1], buffer, ft_strlen(buffer));
	write(dlk->heredoc_pipe[1], "\n", 1);
	*ptr_count += 1;
	free(buffer);
}
