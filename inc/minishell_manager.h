/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_manager.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:26:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 13:30:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MANAGER_H
# define MINISHELL_MANAGER_H

#include "./minishell_structures.h"

void			minishell_destroyer(t_minishell *minishell);
t_minishell		*minishell_creator(void);

#endif