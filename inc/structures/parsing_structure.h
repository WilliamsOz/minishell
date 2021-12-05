/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_structure.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:40 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/05 15:20:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_STRUCTURE_H
# define PARSING_STRUCTURE_H

typedef struct	s_parsing_err
{
	int			simple_cote;
	int			double_cote;
	int			simple_pipe;
	int			double_pipe;
	int			pipeline_next_to_pipeline;
	int			pipeline_next_to_null;
}				t_parsing_err;

#endif