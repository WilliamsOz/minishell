/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:15:26 by user42            #+#    #+#             */
/*   Updated: 2022/01/05 11:28:46 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_minishell	*free_child(t_minishell *minishell)
{
	minishell->cmd = cmd_destructor(minishell->cmd);
	minishell = tab_env_destructor(minishell);
	minishell = destroy_data(minishell);
	minishell = destroy_all_data(minishell);
	return (minishell);
}
