/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_called.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:58:37 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/14 17:21:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*end_called(t_dlk_list *dlk, char *buffer)
{
	free(buffer);
	close(dlk->heredoc_pipe[1]);
	return (dlk);
}
