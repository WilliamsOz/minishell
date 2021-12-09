/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_structure.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:15:49 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/09 16:43:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LINKED_LIST_STRUCTURE_H
# define DOUBLE_LINKED_LIST_STRUCTURE_H

typedef struct    s_dlk_list
{
	char				*token;
	struct s_dlk_list	*next;
	struct s_dlk_list	*previous;
	int					here_doc;
	int					lower_rafter;
	int					upper_rafter;
	int					double_upper_rafter;
	int					pipeline;
	int					is_metacharacter;
	int					simple_quote;
	int					double_quote;
	int					quote_ind;
	int					pipeline_next_to_pipeline;
}						t_dlk_list;

#endif