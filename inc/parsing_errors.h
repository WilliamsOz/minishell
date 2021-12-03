/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:42:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/03 17:58:20 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ERRORS_H
# define PARSING_ERRORS_H

int				unspecified_char(char *line);
int				quote_not_closed(t_parsing_err *parsing_err, int i,
	char *line);
t_minishell		*check_interpretation_errors(t_minishell *minishell);

#endif