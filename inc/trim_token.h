/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:07 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/10 19:18:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIM_TOKEN_H
# define TRIM_TOKEN_H

char		*copy_expanded_value(char *token, char **env, char *tmp, int *p_j);
int			get_expanded_len(char *token, int *ptr_i, int j, char **env);
int			get_end_of_expansion(char *token, char **env, int i, int j);
int			get_expanded_index(char *token, char **env, int i, int j);
int			existing_expand(char *token, char **env, int i, int j);
int			quotes_remaining(char *token, int i);
int			get_between_len(char *token, char **env, int do_expansion, int i);
char		*get_between_quote(char *token, int *ptr_i, char **env);
char		*bq_get_final_token(char *token, char *tmp, char **env, int i);
int			bq_get_len(char *token, int *ptr_i, int len, char **env);
char		*before_quote(t_trim *trim, char *token, int *ptr_i, char **env);
void		trim_malloc_failed(t_minishell *minishell, t_trim *trim);
void		destroy_trim(t_trim *trim);
t_trim		*init_trim(t_minishell *minishell);
int			need_to_be_trim(char *token, int i);
t_minishell	*trim_token(t_minishell *minishell, char **env);

#endif