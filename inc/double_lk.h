/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:02:31 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/12 17:11:51 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LK_H
# define DOUBLE_LK_H

t_dlk_list	*get_coted_token(t_dlk_list *dlk, char *str, int *p_i, int j);
int			skip_space(char *line, int i);
t_dlk_list	*get_metacharacter(t_dlk_list *dlk, char c, int *ptr_i, char *str);
int			is_metacharacter(char c);
t_dlk_list	*init_dlk_metacharacter(t_dlk_list *dlk);
void		init_dlk_token_failed(t_minishell *minishell);
void		init_dlk_creator_failed(t_minishell *minishell);
int			is_it_a_quote(char c);


#endif