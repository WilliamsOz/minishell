/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:07 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/22 20:03:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIM_TOKEN_H
# define TRIM_TOKEN_H

char		*cpy_status(char *tmp, int s_h, int *ptr_i, int *ptr_j);
int			get_status_len(int *ptr_i, int tmp);
char		*trim(t_minishell *minishell, char *token, int i, char **env);
int			skip_unk_exp(char *token, int i);
char		*copy_expanded_value(char *token, char **env, char *tmp, int *p_j);
int			get_expanded_len(char *token, int *ptr_i, int j, char **env);
int			get_end_of_expansion(char *token, char **env, int i, int j);
int			get_expanded_index(char *token, char **env, int i, int j);
int			dc_existing_expand(char *token, char **env, int i, int j);
int			existing_expand(char *token, char **env, int i, int j);
char		*get_trimed_token(char *token, char *tmp, char **env, int *ptr_i);
int			get_final_len(char *token, char **env, int do_expansion, int i);
int			need_to_be_trim(char *token, int i);
t_minishell	*trim_token(t_minishell *minishell, char **env);

#endif