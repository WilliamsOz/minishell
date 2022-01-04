/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_failed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:17:05 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 12:48:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_parsing_failed(t_minishell *m)
{
	m->env = env_destructor(m->env);
	m = minishell_destroyer(m);
	exit (errno);
}
