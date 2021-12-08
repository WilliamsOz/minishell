# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 17:32:48 by wiozsert          #+#    #+#              #
#    Updated: 2021/12/08 19:03:13 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror #-fsanitize=address
RLFLAGS = -lreadline

#libft
LIBFTLIB = libft.a
LIBFTFILESO = ./libft/ft_pustr_fd.o ./libft/ft_strcmp.o ./libft/ft_strlen.o

# srcs
# PATHSRCS = ./srcs/
# PATHMIMA = $(PATHSRCS)minishell_manager/
# PATHPAEM = $(PATHSRCS)parsing_err_manager/
# PATHPAER = $(PATHSRCS)parsing_errors/
# PATHUTLS = $(PATHSRCS)utils/
# PATHEXCA = $(PATHSRCS)exit_call/
# FILESC = $(PATHSRCS)minishell.c $(PATHMIMA)minishell_creator.c \
# $(PATHMIMA)minishell_destroyer.c $(PATHPAEM)parsing_err_creator.c \
# $(PATHPAEM)parsing_err_desroyer.c $(PATHPAER)check_quotes_closed.c \
# $(PATHUTLS)free_line.c $(PATHEXCA)check_exit_call.c $(PATHEXCA)exit_called.c
FILESC = $(shell find ./srcs -name "*.c")
OBJS = $(addsuffix .o, $(notdir $(basename $(FILESC))))

all : $(NAME)

$(NAME) : $(FILESC)
	mkdir -p obj
	make -C ./libft
	mv $(LIBFTFILESO) ./obj/
	mv ./libft/$(LIBFTLIB) .
	cc $(FLAGS) -c $(FILESC)
	cc $(FLAGS) $(OBJS) $(LIBFTLIB) $(RLFLAGS) -o $(NAME)
	mv $(OBJS) $(LIBFTLIB) ./obj

clean :
	rm -Rf ./obj $(LIBFTLIB)

fclean : clean
	rm -Rf $(NAME)

re : fclean all

build :
	find ./srcs -name "*.c"

# bonus :
# @sed -i "s/# define BONUS 1/# define BONUS 0/g" ./inc/pipex.h