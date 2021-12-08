/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:07 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 16:27:28 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIM_TOKEN_H
# define TRIM_TOKEN_H

char		*before_quote(t_trim *trim, char *token, int *ptr_i, char **env);
void		trim_malloc_failed(t_minishell *minishell, t_trim *trim);
void		destroy_trim(t_trim *trim);
t_trim		*init_trim(t_minishell *minishell);
int			need_to_be_trim(char *token, int i);
t_minishell	*trim_token(t_minishell *minishell, char **env);

#endif