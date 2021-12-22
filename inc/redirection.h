/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:40:30 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/22 15:23:58 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

t_dlk_list	*performs_redirection(t_dlk_list *dlk);
int			ur_bad_redirection(t_minishell *m, t_dlk_list *dlk, char **env);
int			lr_bad_redirection(t_minishell *m, t_dlk_list *dlk, char **env);
int			redirection_check(t_minishell *m, char **env);

#endif