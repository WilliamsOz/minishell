/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:10:57 by user42            #+#    #+#             */
/*   Updated: 2021/12/26 15:50:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

t_dlk_list	*get_tab_cmd(t_minishell *minishell, t_dlk_list *dlk);
t_dlk_list	*memset_cmd(t_dlk_list *dlk);

#endif