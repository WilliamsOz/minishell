# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 17:32:48 by wiozsert          #+#    #+#              #
#    Updated: 2021/12/02 13:18:50 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror #-fsanitize=address
RLFLAGS = -lreadline

#libft
LIBFTLIB = libft.a
LIBFTFILESO = ./libft/ft_pustr_fd.o ./libft/ft_strcmp.o ./libft/ft_strlen.o

#srcs
PATHSRCS = ./srcs/
PATHPAER = $(PATHSRCS)parsing_errors/
PATHUTLS = $(PATHSRCS)utils/
PATHMIMA = $(PATHSRCS)minishell_manager/
FILESC = $(PATHSRCS)minishell.c $(PATHPAER)are_quotes_closed.c \
$(PATHUTLS)free_line.c $(PATHMIMA)minishell_creator.c
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

# bonus :
# @sed -i "s/# define BONUS 1/# define BONUS 0/g" ./inc/pipex.h