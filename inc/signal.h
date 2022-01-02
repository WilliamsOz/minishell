/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:01:49 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 14:58:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

void	cmd_handlers(int signum);
void	handle_sigchild(int sig);
void	rl_handler(int signum);
void	hd_handler(int signum);
void	handle_rl_signal();

#endif