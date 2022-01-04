/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:15:03 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/04 17:11:29 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		find_env_var(char *var, char *pwd_header);
void	cd_to_home(t_env *env);
void	move_to_root(t_env *env);
void	cd_builtin(t_cmd *cmd, t_env **env);

void	echo_builtin(t_cmd *cmd);
void	env_builtin(t_env *env);
void	exit_builtin(t_cmd *cmd);
void	pwd_builtin(t_cmd *cmd, t_env *env);
void	unset_builtin(t_cmd *cmd, t_env **env);
void	export_builtin(t_cmd *cmd, t_env **env);
void	execute_builtin(t_minishell *m, t_cmd *tmp_cmd);
int		is_builtin(char *str);

#endif