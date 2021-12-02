/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_manager.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:26:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/02 14:56:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MANAGER_H
# define MINISHELL_MANAGER_H

typedef struct	s_minishell
{
	char			*line;
	t_parsing_err	*parsing_err;
}				t_minishell;

void			minishell_destroyer(t_minishell *minishell);
t_minishell		*minishell_creator(void);

#endif