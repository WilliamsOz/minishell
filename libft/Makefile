# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 12:28:25 by wiozsert          #+#    #+#              #
#    Updated: 2022/01/04 16:59:13 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FILESC = ft_pustr_fd.c ft_strcmp.c ft_strlen.c ft_putnbr_fd.c \
ft_itoa.c ft_atoi.c ft_isdigit.c ft_split.c ft_strjoin.c ft_strdup.c \

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