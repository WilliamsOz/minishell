/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:42:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 13:04:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ERRORS_H
# define PARSING_ERRORS_H

int				check_double_upper_rafter(t_dlk_list *dlk);
int				lower_rafter_errors(t_dlk_list *dlk);
int				upper_rafter_errors(t_dlk_list *dlk);
int				check_rafter_errors(t_dlk_list *dlk);
int				check_pipeline_errors(t_dlk_list *tmp);
int				check_here_doc_errors(t_dlk_list *tmp);
int				check_special_chars(t_dlk_list *dlk);
t_minishell		*is_logic_input(t_minishell *minishell);
t_minishell		*special_char_found(t_minishell *minishell);
int				is_pipeline_next_to_cmd(t_dlk_list *dlk);
t_minishell		*are_quotes_closed(t_minishell*minishell, int i, char *line);

#endif