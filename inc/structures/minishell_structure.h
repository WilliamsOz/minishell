/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structure.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:21:34 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:45:13 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTURE_H
# define MINISHELL_STRUCTURE_H

typedef struct s_minishell
{
	char			*line;
	t_parsing_err	*parsing_err;
	t_dlk_list		*d_lk;
	t_env			*env;
	t_cmd			*cmd;
	char			**tab_env;
}				t_minishell;

#endif