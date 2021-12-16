/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:40:30 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 15:46:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

int	lr_bad_redirection(t_minishell *m, t_dlk_list *dlk, char **env);
int	redirection_check(t_minishell *m, char **env);

#endif