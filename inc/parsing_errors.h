/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:42:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/04 11:27:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ERRORS_H
# define PARSING_ERRORS_H

int				check_pipeline_errors(t_dlk_list *dlk);
t_minishell		*check_metacharacter_errors(t_minishell *minishell);
int				unspecified_char(char *line);
int				quote_not_closed(t_parsing_err *parsing_err, int i,
	char *line);
t_minishell		*check_interpretation_errors(t_minishell *minishell);

#endif