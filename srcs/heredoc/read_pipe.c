/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:03:18 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/14 17:25:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*read_on_hd_pipe(t_minishell *m, char *buf, char **env, int *ptr_eof)
{
	buf = NULL;
	write(1, ">", 1);
	*ptr_eof = get_next_line(0, &buf);
	if (*ptr_eof > 0)
		buf = get_new_hd(m, buf, env, 0);
	return (buf);
}
