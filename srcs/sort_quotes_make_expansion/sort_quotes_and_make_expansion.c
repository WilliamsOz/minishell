/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quotes_and_make_expansion.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:42:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 11:38:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*sort_quotes_and_make_expansion(t_minishell *minishell, char **env)
{
	(void)env;
	minishell->d_lk = sort_quotes(minishell->d_lk);
	minishell->d_lk = make_expansion(minishell->d_lk);
	return (minishell);
}
