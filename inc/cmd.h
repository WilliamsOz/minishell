/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:10:57 by user42            #+#    #+#             */
/*   Updated: 2021/12/27 21:55:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

t_cmd		*init_cmd_path(t_cmd *cmd);
t_cmd		*cpy_cmd_from_dlk(t_cmd *cmd, t_dlk_list *dlk);
t_dlk_list	*get_dlk_cmd(t_minishell *minishell, t_dlk_list *dlk);
t_dlk_list	*memset_dlk_cmd(t_dlk_list *dlk);
void		mall_root_cmd_failed(t_minishell *m);
void		mall_new_cmd_failed(t_minishell *m);
t_cmd		*init_cmd(t_minishell *m, t_dlk_list *dlk);
t_minishell	*get_cmd(t_minishell *m, t_dlk_list *dlk);

#endif