/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:56:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/17 14:37:21 by wiozsert         ###   ########.fr       */
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
