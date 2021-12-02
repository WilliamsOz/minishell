/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structure.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:21:34 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 18:29:58 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTURE_H
# define MINISHELL_STRUCTURE_H

typedef struct	s_minishell
{
	char			*line;
	t_parsing_err	*parsing_err;
}				t_minishell;

#endif