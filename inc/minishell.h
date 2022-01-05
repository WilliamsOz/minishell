/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:42:09 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 16:48:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _GNU_SOURCE
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"
# include "./structures/env_structure.h"
# include "./structures/parsing_structure.h"
# include "./structures/double_linked_list_structure.h"
# include "./structures/cmd_structure.h"
# include "./structures/minishell_structure.h"
# include "./structures/trim_token_structure.h"
# include "./env.h"
# include "./parsing_errors.h"
# include "./free_line.h"
# include "./double_lk.h"
# include "./trim_token.h"
# include "./heredoc.h"
# include "./signal.h"
# include "./redirection.h"
# include "./cmd.h"
# include "./builtins.h"
# include "./execution.h"
# define BACKSLASH_CHAR 92
# define SEMICOLON 59
# define SIMPLE_COTE 39
# define DOUBLE_COTE 34
# define LOWER_RAFTER 60
# define UPPER_RAFTER 62
# define PIPELINE 124
# define HEREDOC_CASE 0

int	g_signal_handler;

int				is_rafter(t_dlk_list *dlk);
void			minishell_eof_called(void);
t_minishell		*destroy_data(t_minishell *minishell);
t_parsing_err	*parsing_err_creator(void);
t_parsing_err	*parsing_err_destroyer(t_parsing_err *parsing_err);
t_minishell		*minishell_destroyer(t_minishell *minishell);
t_minishell		*minishell_creator(char **env);
t_dlk_list		*double_lk_destroyer(t_dlk_list *d_lk);
t_dlk_list		*double_lk_creator(t_minishell *minishell, char *line, int i);
t_minishell		*destroy_all_data(t_minishell *minishell);
t_minishell		*destroy_cmd_data(t_minishell *m);

#endif