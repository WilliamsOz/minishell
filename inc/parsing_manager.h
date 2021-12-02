/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:27:37 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 15:05:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_MANAGER_H
# define PARSING_MANAGER_H

typedef struct	s_parsing_err
{
	int			exit_called;
	int			simple_cote;
	int			double_cote;
}				t_parsing_err;

t_parsing_err	*parsing_err_creator();
void		parsing_err_destroyer(t_parsing_err *parsing_err);

#endif