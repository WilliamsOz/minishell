/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:15:03 by oozsertt          #+#    #+#             */
/*   Updated: 2021/12/30 18:38:19 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	echo_builtin(t_cmd *cmd);
void	cd_builtin(t_cmd *cmd, t_env **env);
void	env_builtin(t_env *env);
void	exit_builtin(t_cmd *cmd);
void	pwd_builtin(t_cmd *cmd, t_env *env);
void	unset_builtin(t_cmd *cmd, t_env **env);
void	export_builtin(t_cmd *cmd, t_env **env);

#endif