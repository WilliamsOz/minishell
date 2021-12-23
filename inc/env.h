/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:29:01 by user42            #+#    #+#             */
/*   Updated: 2021/12/23 18:45:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

t_env	*create_var(t_minishell *m, char **env, int i, int j);
t_env	*create_root(t_minishell *m, t_env **root, char **env);
void	env_destructor(t_env *env);
t_env	*env_creator(t_minishell *m, char **env);

#endif