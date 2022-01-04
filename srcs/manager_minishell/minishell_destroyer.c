/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_destroyer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:18:59 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 12:08:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*minishell_destroyer(t_minishell *minishell)
{
	free(minishell);
	minishell = NULL;
	return (minishell);
}
