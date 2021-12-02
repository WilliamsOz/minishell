/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structures.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:28:55 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 13:34:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTURES_H
# define MINISHELL_STRUCTURES_H

#include "./parsing_err_structure.h"

typedef struct	s_minishell
{
	char			*line;
	t_parsing_err	*parsing_err;
}				t_minishell;

#endif