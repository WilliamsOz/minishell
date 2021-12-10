/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structure.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:21:34 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/10 12:22:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTURE_H
# define MINISHELL_STRUCTURE_H

typedef struct	s_minishell
{
	char			*line;
	t_parsing_err	*parsing_err;
	t_dlk_list		*d_lk;
}				t_minishell;

#endif