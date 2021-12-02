/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err_structure.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:31:39 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 13:32:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ERR_STRUCTURE_H
# define PARSING_ERR_STRUCTURE_H

typedef struct	s_parsing_err
{
	int			exit_called;
	int			simple_cote;
	int			double_cote;
}				t_parsing_err;

#endif