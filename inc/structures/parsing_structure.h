/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_structure.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:40 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/03 13:44:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_STRUCTURE_H
# define PARSING_STRUCTURE_H

typedef struct	s_parsing_err
{
	int			exit_called;
	int			simple_cote;
	int			double_cote;
}				t_parsing_err;

#endif