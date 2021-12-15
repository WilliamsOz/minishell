# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 12:28:25 by wiozsert          #+#    #+#              #
#    Updated: 2021/12/15 19:10:55 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FILESC = ft_pustr_fd.c ft_strcmp.c ft_strlen.c get_next_line.c ft_putnbr_fd.c \
ft_itoa.c
OBJS = $(addsuffix .o, $(notdir $(basename $(FILESC))))

all : $(NAME)

$(NAME) :
	@cc $(FLAGS) -c $(FILESC)
	@ar -rcs $(NAME) $(OBJS)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all