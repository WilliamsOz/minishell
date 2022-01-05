/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:06:38 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 17:14:01 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

void		command_not_found(char *cmd);
void		print_core_dumped(void);
void		no_file_or_directory(char *cmd);
int			path_removed(char **env);
t_minishell	*free_child(t_minishell *m);
t_minishell	*execute_last_cmd(t_minishell *m, t_cmd *tmp_cmd);
t_minishell	*rw_inside_pipes(t_minishell *m, t_cmd *cmd);
t_minishell	*exec_in_pipe(t_minishell *minishell, t_cmd *cmd);
t_cmd		*last_entry(t_minishell *minishell, t_cmd *tmp_cmd);
t_cmd		*mid_entry(t_minishell *minishell, t_cmd *tmp_cmd);
t_cmd		*first_entry(t_minishell *minishell, t_cmd *tmp_cmd);
void		exec_one_cmd(t_minishell *m, t_cmd *tmp_cmd, char **env);
void		execution(t_minishell *minishell, char **env);

#endif