/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:07 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/01 18:44:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIM_TOKEN_H
# define TRIM_TOKEN_H

t_dlk_list	*leave_one_token(t_dlk_list *dlk);
int			still_env_key(char c);
char		*cpy_status(char *tmp, int *ptr_i, int *ptr_j);
int			get_status_len(int *ptr_i, int tmp);
char		*trim(t_minishell *minishell, char *token, int i);
int			skip_unk_exp(char *token, int i);
char		*copy_expanded_value(char *token, t_env *env, char *dest, int *p_j);
int			get_expanded_len(char *token, int *ptr_i, int j, t_env *env);
int			get_end_of_expansion(char *token, int i);
int			get_expanded_index(char *token, t_env *env, int i);
int			dc_existing_expand(char *token, t_env *env, int i);
int			existing_expand(char *token, t_env *env, int i);
char		*get_trimed_token(char *token, char *tmp, t_env *env, int *ptr_i);
int			get_final_len(char *token, t_env *env, int do_expansion, int i);
int			need_to_be_trim(char *token, int i);
t_minishell	*trim_token(t_minishell *minishell);

#endif