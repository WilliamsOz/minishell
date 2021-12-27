/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:40:30 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/27 15:38:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

t_dlk_list	*redirect_d_ur(t_dlk_list *dlk, t_cmd *cmd);
t_dlk_list	*redirect_ur(t_dlk_list *dlk, t_cmd *cmd);
t_minishell	*performs_redirection(t_minishell *m);
int			ur_bad_redirection(t_minishell *m, t_dlk_list *dlk);
int			lr_bad_redirection(t_minishell *m, t_dlk_list *dlk);
int			redirection_check(t_minishell *m);
t_dlk_list	*init_dlk_redirect(t_dlk_list *dlk);

#endif