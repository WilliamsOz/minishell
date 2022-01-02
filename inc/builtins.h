/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:15:03 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/02 19:21:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	echo_builtin(t_cmd *cmd);
void	cd_builtin(t_cmd *cmd, t_env **env);
void	env_builtin(t_env *env);
void	exit_builtin(t_minishell *m, t_cmd *cmd);
void	pwd_builtin(t_cmd *cmd, t_env *env);
void	unset_builtin(t_cmd *cmd, t_env **env);
void	export_builtin(t_cmd *cmd, t_env **env);
void	execute_builtin(t_minishell *m, t_cmd *tmp_cmd);
int		is_builtin(char *str);

#endif