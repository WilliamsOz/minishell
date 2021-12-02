/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:42:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 18:36:49 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ERRORS_H
# define PARSING_ERRORS_H

t_parsing_err	*parsing_err_creator();
void		parsing_err_destroyer(t_parsing_err *parsing_err);
void			minishell_destroyer(t_minishell *minishell);
t_minishell		*minishell_creator(void);
int	quotes_closed(t_parsing_err *parsing_err, int i, char *line);

#endif