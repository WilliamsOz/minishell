/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:10:57 by user42            #+#    #+#             */
/*   Updated: 2021/12/27 15:19:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

t_dlk_list	*get_dlk_cmd(t_minishell *minishell, t_dlk_list *dlk);
t_dlk_list	*memset_dlk_cmd(t_dlk_list *dlk);
void		mall_root_cmd_failed(t_minishell *m);
void		mall_new_cmd_failed(t_minishell *m);

#endif