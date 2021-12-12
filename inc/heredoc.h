/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:15:02 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/12 18:07:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

t_dlk_list	*__init_heredoc_pipes__(t_minishell *m, t_dlk_list *dlk, int ind);
void		pipe_failed(t_minishell *minishell);
t_dlk_list	*memset_heredoc_pipe(t_dlk_list *dlk);
void		close_heredoc_pipes(t_dlk_list *dlk);

#endif