# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 17:32:48 by wiozsert          #+#    #+#              #
#    Updated: 2021/12/01 17:45:14 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror #-fsanitize=address

#srcs
FILESC = ./srcs/minishell.c
OBJS = $(addsuffix .o, $(notdir $(basename $(FILESC))))

all : $(NAME)

$(NAME) : $(FILESC)
	mkdir -p obj
	cc $(FLAGS) -c $(FILESC)
	cc $(FLAGS) $(OBJS) -o $(NAME)
	mv $(OBJS) ./obj

clean :
	rm -Rf ./obj

fclean : clean
	rm -Rf $(NAME)

re : fclean all

# bonus :
# @sed -i "s/# define BONUS 1/# define BONUS 0/g" ./inc/pipex.h