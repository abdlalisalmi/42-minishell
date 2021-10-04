# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:01:35 by aes-salm          #+#    #+#              #
#    Updated: 2021/10/04 12:06:05 by aes-salm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
SRCS 	=	start_execution.c \
			execution/execute_single_command.c \
			utils/free_d_pointer.c \
			utils/get_cmd_path.c \
			env/collect_env.c \
			env/get_env.c \
			env/set_env.c \
			functions/ft_strlen.c \
			functions/ft_putstr_fd.c \
			functions/ft_memcopy.c \
			functions/ft_strcmp.c \
			functions/ft_strdup.c \
			functions/ft_strchr.c \
			functions/ft_isdigit.c \
			functions/ft_strappend.c \
			functions/ft_split.c \
			builtins/ft_echo.c \
			builtins/ft_cd.c \
			builtins/ft_env.c \
			builtins/ft_exit.c \
			builtins/ft_export.c \
			builtins/ft_pwd.c \
			builtins/ft_unset.c \
			

			
			
			

$(NAME) : 	$(SRCS)
			@ $(CC) $(FLAGS) -c $(SRCS)
			@ ar rc $(NAME) *.o
			@ $(CC) $(FLAGS) start_execution.c $(NAME) -o minishell -g3 -fsanitize=address


all: 		$(NAME)

clean:
			@ rm -rf *.o

fclean: 	clean
			@ rm -rf $(NAME) minishell minishell.dSYM

re: 		fclean all

build:		re
			@ rm -rf *.o $(NAME) minishell.dSYM