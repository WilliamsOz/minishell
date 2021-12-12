/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list_structure.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:15:49 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/12 12:21:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LINKED_LIST_STRUCTURE_H
# define DOUBLE_LINKED_LIST_STRUCTURE_H

typedef struct    s_dlk_list
{
	char				*token;
	int					heredoc_pipe[2];
	char				*limiter;
	int					token_len;
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