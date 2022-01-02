/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:15:03 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/01 23:50:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	execute_builtin(t_minishell *minishell, t_cmd *cmd);
int		is_builtin(char *cmd);
void	echo_builtin(t_cmd *cmd);
void	cd_builtin(t_cmd *cmd, t_env **env);
void	env_builtin(t_env *env);
void	exit_builtin(t_cmd *cmd);
void	pwd_builtin(t_cmd *cmd, t_env *env);

#endif