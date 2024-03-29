/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallloc_failed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:38:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 18:21:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	mall_trimed_line_failed(t_minishell *m)
{
	strerror(errno);
	m->env = env_destructor(m->env);
	m = destroy_all_data(m);
	exit (errno);
}
