/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:42:09 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/02 00:23:04 by user42           ###   ########.fr       */
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
# include "./env.h"
# include "./parsing_errors.h"
# include "./free_line.h"
# include "./double_lk.h"
# include "./structures/trim_token_structure.h"
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

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

# define REDCLR printf("\033[0;31m");
# define GREENCLR printf("\033[0;32m");
# define YELLOWCLR printf("\033[0;33m");
# define BLUECLR printf("\033[0;34m");
# define PURPLECLR printf("\033[0;35m");
# define CYANCLR printf("\033[0;36m");
# define WHITECLR printf("\033[0;37m");
# define STOPCLR printf("\033[0m");
# define ICI printf("ICI\n");
# define PS(x) printf("%s\n", x);
# define PC(x) printf("%c\n", x);
# define PD(x) printf("%d\n", x);
# define PP(x) printf("%p\n", x);
# define ex exit(EXIT_SUCCESS);
void    show_dlk(t_dlk_list *dlk);
# define SMDLK(x) show_dlk(x);
# define PRTDLKCMD print_dlk_cmd(dlk);
void	print_cmd(t_cmd *cmd);
# define PRTCMD(x) print_cmd(x);

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

int signal_handler;

int				is_rafter(t_dlk_list *dlk);
void			minishell_eof_called(void);
t_parsing_err	*parsing_err_creator();
void			parsing_err_destroyer(t_parsing_err *parsing_err);
void			minishell_destroyer(t_minishell *minishell);
t_minishell		*minishell_creator(char **env);
t_dlk_list		*double_lk_destroyer(t_dlk_list *d_lk);
t_dlk_list		*double_lk_creator(t_minishell *minishell, char *line, int i);
t_minishell		*destroy_all_data(t_minishell *minishell);

#endif