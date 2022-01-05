/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:15:02 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:58:59 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

t_minishell	*w_inside_child(t_minishell *m, t_dlk_list *tmp);
void		mall_trimed_line_failed(t_minishell *m);
void		fork_failed(t_minishell *m);
void		close_heredoc_pipes(t_dlk_list *dlk);
t_minishell	*eof_called(t_minishell *minishell, t_dlk_list *dlk);
void		pipe_failed(t_minishell *minishell);
t_dlk_list	*call_child(t_minishell *m, t_dlk_list *tmp, int status);
t_dlk_list	*hd_prepare_dlk(t_dlk_list *dlk);
t_minishell	*heredoc(t_minishell *m, t_dlk_list *dlk);

#endif