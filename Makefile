# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 17:32:48 by wiozsert          #+#    #+#              #
#    Updated: 2022/01/05 13:04:47 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror -fcommon
RLFLAGS = -lreadline

LIBFTLIB = libft.a
LIBFTFILESO = ./libft/ft_pustr_fd.o ./libft/ft_strcmp.o ./libft/ft_strlen.o \
./libft/ft_putnbr_fd.o ./libft/ft_itoa.o \
./libft/ft_isdigit.o ./libft/ft_split.o ./libft/ft_atoi.o ./libft/ft_strjoin.o \
./libft/ft_strdup.o 

FILESC = ./srcs/trim_tokens/get_final_token.c ./srcs/trim_tokens/trim_token.c \
./srcs/trim_tokens/expansion/status_len.c \
./srcs/trim_tokens/expansion/copy_status.c \
./srcs/trim_tokens/expansion/get_expansion_end.c \
./srcs/trim_tokens/expansion/existing_exansion.c \
./srcs/trim_tokens/expansion/cpy_expansion.c \
./srcs/trim_tokens/expansion/get_expansion_index.c \
./srcs/trim_tokens/expansion/skip_unknow_expansion.c \
./srcs/trim_tokens/expansion/get_expansion_len.c \
./srcs/trim_tokens/leave_one_token.c ./srcs/trim_tokens/need_to_be_trim.c \
./srcs/trim_tokens/get_final_len.c ./srcs/builtins/export_builtin.c \
./srcs/builtins/is_builtin.c ./srcs/builtins/echo_builtin.c \
./srcs/builtins/pwd_builtin.c ./srcs/builtins/env_builtin.c \
./srcs/builtins/unset_builtin.c ./srcs/builtins/execute_builtin.c \
./srcs/builtins/cd_builtin/cd_builtin.c \
./srcs/builtins/cd_builtin/cd_to_home.c \
./srcs/builtins/cd_builtin/move_to_root.c ./srcs/builtins/exit_builtin.c \
./srcs/builtins/find_env_var.c ./srcs/redirection/init_rdrct.c \
./srcs/redirection/lr_redirect.c ./srcs/redirection/hd_redirect.c \
./srcs/redirection/performs_rdcts.c \
./srcs/redirection/check/redirection_check.c \
./srcs/redirection/check/lr_check.c ./srcs/redirection/check/ur_check.c \
./srcs/redirection/ur_redirect.c ./srcs/redirection/d_ur_redirect.c\
./srcs/env/copy_var.c ./srcs/env/mall_tab_env_failed.c \
./srcs/env/env_creator.c ./srcs/env/tab_env_creator.c ./srcs/env/manager_env.c \
./srcs/signal/cmd_handlers.c ./srcs/signal/handlers.c \
./srcs/minishell.c ./srcs/manager_minishell/minishell_destroyer.c \
./srcs/manager_minishell/minishell_creator.c ./srcs/execution/execution.c \
./srcs/execution/last_entry/execute_last_cmd.c \
./srcs/execution/last_entry/last_entry.c \
./srcs/execution/first_entry/exec_in_pipe.c \
./srcs/execution/first_entry/one_cmd.c \
./srcs/execution/first_entry/first_entry.c \
./srcs/execution/mid_entry/rw_inside_pipes.c \
./srcs/execution/mid_entry/mid_entry.c ./srcs/execution/free_child.c \
./srcs/manager_dlk/metacharacter.c ./srcs/manager_dlk/dlk_malloc_failed.c \
./srcs/manager_dlk/skip_space_character.c ./srcs/manager_dlk/is_it_a_quote.c \
./srcs/manager_dlk/double_lk_creator.c \
./srcs/manager_dlk/double_lk_destroyer.c \
./srcs/manager_dlk/copy_token_untill_next_cote.c ./srcs/heredoc/pipe_failed.c \
./srcs/heredoc/prepare_d_lk.c ./srcs/heredoc/fork_failed.c \
./srcs/heredoc/mallloc_failed.c ./srcs/heredoc/heredoc.c \
./srcs/heredoc/hd_call_child.c ./srcs/heredoc/close_pipes.c \
./srcs/heredoc/eof_called.c ./srcs/utils/minishell_eof_called.c \
./srcs/utils/free_line.c ./srcs/utils/destroyer.c ./srcs/utils/is_rafter.c \
./srcs/manager_parsing_err/parsing_err_creator.c \
./srcs/manager_parsing_err/parsing_err_desroyer.c \
./srcs/parsing_errors/double_upper_rafter.c \
./srcs/parsing_errors/closed_quotes.c \
./srcs/parsing_errors/init_parsing_failed.c \
./srcs/parsing_errors/upper_rafter.c ./srcs/parsing_errors/special_chars.c \
./srcs/parsing_errors/here_doc.c ./srcs/parsing_errors/rafters.c \
./srcs/parsing_errors/pipeline.c ./srcs/parsing_errors/lower_rafter.c \
./srcs/parsing_errors/logic_entry.c ./srcs/cmd/not_found.c \
./srcs/cmd/open_pipes.c ./srcs/cmd/memset_dlk_cmd.c ./srcs/cmd/move_to_value.c \
./srcs/cmd/cmd_destructor.c ./srcs/cmd/cmd_malloc_failed.c \
./srcs/cmd/get_dlk_cmd.c ./srcs/cmd/init_cmd_path.c \
./srcs/cmd/cpy_cmd_from_dlk.c ./srcs/cmd/get_cmd.c \
./srcs/cmd/init_cmd.c ./srcs/cmd/find_path.c ./srcs/execution/path_removed.c \
./srcs/execution/print_error.c

OBJS = $(addsuffix .o, $(notdir $(basename $(FILESC))))

all : $(NAME)

$(NAME) : $(FILESC)
	@mkdir -p obj
	@make -C ./libft
	@mv $(LIBFTFILESO) ./obj/
	@mv ./libft/$(LIBFTLIB) .
	@cc $(FLAGS) -c $(FILESC)
	@cc $(FLAGS) $(OBJS) $(LIBFTLIB) $(RLFLAGS) -o $(NAME)
	@mv $(OBJS) $(LIBFTLIB) ./obj

clean :
	@rm -Rf ./obj $(LIBFTLIB)

fclean : clean
	@rm -Rf $(NAME)

re : fclean all