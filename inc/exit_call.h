/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_call.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:06:00 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 18:32:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_CALL_H
# define EXIT_CALL_H

int		exit_call_check(char *line, char *exit, int i, int j);
void	exit_called(t_minishell *minishell);

#endif