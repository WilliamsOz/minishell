/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_structure.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:40 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:45:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_STRUCTURE_H
# define PARSING_STRUCTURE_H

typedef struct s_parsing_err
{
	int			simple_cote;
	int			double_cote;
	int			simple_pipe;
	int			double_pipe;
}				t_parsing_err;

#endif