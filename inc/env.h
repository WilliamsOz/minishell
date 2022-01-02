/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:29:01 by user42            #+#    #+#             */
/*   Updated: 2022/01/02 18:18:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

void		mall_str_tab_env_failed(t_minishell *m);
void		mall_tab_env_failed(t_minishell *m);
t_minishell	*tab_env_destructor(t_minishell *m);
t_minishell	*tab_env_creator(t_minishell *m);
t_env		*create_var(t_minishell *m, char **env, int i, int j);
t_env		*create_root(t_minishell *m, t_env **root, char **env);
t_env		*env_destructor(t_env *env);
t_env		*env_creator(t_minishell *m, char **env);

#endif