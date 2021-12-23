/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:40:30 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/23 16:19:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

t_dlk_list	*performs_redirection(t_dlk_list *dlk);
int			ur_bad_redirection(t_minishell *m, t_dlk_list *dlk);
int			lr_bad_redirection(t_minishell *m, t_dlk_list *dlk);
int			redirection_check(t_minishell *m);

#endif