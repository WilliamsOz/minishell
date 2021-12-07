/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_expansion.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:07 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/07 17:04:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_EXPANSION_H
# define QUOTES_EXPANSION_H

t_dlk_list	*make_expansion(t_dlk_list *dlk);
t_dlk_list	*sort_quotes(t_dlk_list *dlk);
t_minishell	*sort_quotes_and_make_expansion(t_minishell *minishell, char *env);

#endif