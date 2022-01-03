/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:06:38 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/03 13:54:35 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

void	execute_last_cmd(t_minishell *m, t_cmd *tmp_cmd, char **env);
void	rw_inside_pipes(t_minishell *m, t_cmd *cmd, char **env);
void	exec_in_pipe(t_minishell *minishell, t_cmd *cmd);
t_cmd	*last_entry(t_minishell *minishell, t_cmd *tmp_cmd, char **env);
t_cmd	*mid_entry(t_minishell *minishell, t_cmd *tmp_cmd, char **env);
t_cmd	*first_entry(t_minishell *minishell, t_cmd *tmp_cmd, char **env);
void	 exec_one_cmd(t_minishell *m, t_cmd *tmp_cmd, char **env);
void	execution(t_minishell *minishell, char **env);

#endif