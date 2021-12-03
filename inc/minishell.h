/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:42:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/03 22:53:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
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
# include "./structures/parsing_structure.h"
# include "./structures/double_linked_list_structure.h"
# include "./structures/minishell_structure.h"
# include "./parsing_errors.h"
# include "./free_line.h"
# include "./double_lk.h"
# define TRUE 1
# define FALSE 0
# define BACKSLASH_CHAR 92
# define SEMICOLON 59
# define SIMPLE_COTE 39
# define DOUBLE_COTE 34
# define LOWER_RAFTER 60
# define UPPER_RAFTER 62
# define PIPELINE 124

# define D printf("ICI\n");
# define PS(x) printf("%s\n", x);
# define PC(x) printf("%c\n", x);
# define PD(x) printf("%d\n", x);
# define PP(x) printf("%p\n", x);
# define ex exit(EXIT_SUCCESS);

t_parsing_err	*parsing_err_creator();
void			parsing_err_destroyer(t_parsing_err *parsing_err);
void			minishell_destroyer(t_minishell *minishell);
t_minishell		*minishell_creator(void);
void			double_lk_destroyer(t_dlk_list *d_lk);
t_dlk_list		*double_lk_creator(t_minishell *minishell, char *line, int i);

#endif