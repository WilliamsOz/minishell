/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:27:37 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 13:34:44 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_MANAGER_H
# define PARSING_MANAGER_H

# include "./minishell_structures.h"

t_minishell	*parsing_err_creator(t_minishell *minishell);
void		*parsing_err_destroyer(t_minishell *minishell);

#endif