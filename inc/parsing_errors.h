/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:42:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/05 15:28:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ERRORS_H
# define PARSING_ERRORS_H

t_minishell		*check_pipeline_errors(t_minishell *minishell,
	t_dlk_list *dlk);
t_minishell		*special_char_found(t_minishell *minishell);
int				check_special_chars(t_dlk_list *dlk);
t_minishell		*check_tokens_errors(t_minishell *minishell);
t_minishell		*are_quotes_closed(t_minishell*minishell, int i, char *line);

#endif