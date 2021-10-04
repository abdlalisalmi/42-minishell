# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 11:54:02 by atahiri           #+#    #+#              #
#    Updated: 2021/10/04 12:42:31 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	main.c\
		utils/trim_spaces.c\
		utils/ft_strdup.c\
		utils/ft_strlen.c\
		utils/ft_putstr_fd.c\
		utils/verif_quotes.c\
		utils/ft_split.c\
		utils/ft_dplen.c\
		utils/print_out.c\
		

INCLUDES =	includes/minishell.h

READLINE_LIB_IMAC = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib \
			   -I /Users/$(USER)/.brew/opt/readline/include

READLINE_LIB_MAC = -lreadline -L /usr/local/opt/readline/lib \
			   -I /usr/local/opt/readline/include

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	@gcc $(FLAGS) $(READLINE_LIB_IMAC) $(SRCS) -o $(NAME)

clean:
			@rm -rf *.o

fclean: 	clean
			@rm -rf $(NAME) minishell.dSYM

re: 		fclean all