/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:15:02 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 00:29:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

t_minishell	*eof_called(t_minishell *minishell, t_dlk_list *dlk);
t_dlk_list	*close_ununsed_pipes(t_dlk_list *dlk);
char		*read_on_hd_pipe(t_minishell *m, char *buf, char **env,
	int *ptr_eof);
t_dlk_list	*end_called(t_dlk_list *dlk, char *buffer);
t_dlk_list	*rd_hd(t_minishell *m, t_dlk_list *dlk, char **env, int ef);
void		write_hd_inside_pipe(t_dlk_list *dlk, char *buffer, int *p_count);
char		*get_new_hd(t_minishell *m, char *buffer, char **env, int i);
int			get_new_heredoc_len(char *buffer, char **env, int i, int len);
int			expansion_needed(char *buffer, int i);
t_dlk_list	*init_heredoc_pipes(t_minishell *m, t_dlk_list *dlk, int ind);
void		pipe_failed(t_minishell *minishell);
t_dlk_list	*memset_heredoc_pipe(t_dlk_list *dlk);
void		close_heredoc_pipes(t_dlk_list *dlk);
t_dlk_list	*heredoc(t_minishell *m, t_dlk_list *dlk, char **env);

#endif