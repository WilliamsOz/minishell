/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:10:57 by user42            #+#    #+#             */
/*   Updated: 2022/01/05 11:45:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

void		not_found(char **path, char **path_cmd);
int			move_to_value(char *env, int i);
t_minishell	*open_pipes(t_minishell *m);
t_cmd		*find_and_get_path_cmd(t_minishell *m, t_cmd *cmd, t_env *env);
t_cmd		*init_cmd_path(t_cmd *cmd);
t_minishell	*cpy_cmd_from_dlk(t_minishell *minishell);
t_dlk_list	*get_dlk_cmd(t_minishell *minishell, t_dlk_list *dlk);
t_dlk_list	*memset_dlk_cmd(t_dlk_list *dlk);
void		mall_new_path_failed(t_minishell *m);
void		mall_root_cmd_failed(t_minishell *m);
void		mall_new_cmd_failed(t_minishell *m);
t_cmd		*cmd_destructor(t_cmd *cmd);
void		init_cmd_failed(t_minishell *m);
t_cmd		*init_cmd(t_minishell *m, t_dlk_list *dlk);
t_minishell	*get_cmd(t_minishell *m);

#endif