/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:15:02 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 14:45:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

t_dlk_list	*hd_prepare_dlk(t_dlk_list *dlk);

t_minishell	*eof_called(t_minishell *minishell, t_dlk_list *dlk);
t_dlk_list	*close_ununsed_pipes(t_dlk_list *dlk);
void		write_hd_inside_pipe(t_dlk_list *dlk, char *buffer, int *p_count);
void		pipe_failed(t_minishell *minishell);
t_dlk_list	*memset_heredoc_pipe(t_dlk_list *dlk);
void		close_heredoc_pipes(t_dlk_list *dlk);
t_dlk_list	*heredoc(t_minishell *m, t_dlk_list *dlk);

#endif