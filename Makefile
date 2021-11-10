NAME = 		minishell

P_SRCS 	= 	parsing/main.c	\
			parsing/utils/trim_spaces.c\
			parsing/utils/ft_strdup.c\
			parsing/utils/ft_strlen.c\
			parsing/utils/ft_putstr_fd.c\
			parsing/utils/verif_quotes.c\
			parsing/utils/ft_split.c\
			parsing/utils/ft_dplen.c\
			parsing/utils/print_out.c\
			parsing/utils/ft_strcmp.c\

E_SRCS 	=	execution/start_execution.c \
			execution/execution/execute_single_command.c \
			execution/utils/free_d_pointer.c \
			execution/utils/get_cmd_path.c \
			execution/env/collect_env.c \
			execution/env/get_env.c \
			execution/env/set_env.c \
			execution/env/to_envp.c \
			execution/functions/ft_strlen.c \
			execution/functions/ft_putstr_fd.c \
			execution/functions/ft_memcopy.c \
			execution/functions/ft_strcmp.c \
			execution/functions/ft_strdup.c \
			execution/functions/ft_strchr.c \
			execution/functions/ft_isdigit.c \
			execution/functions/ft_strappend.c \
			execution/functions/ft_split.c \
			execution/builtins/ft_echo.c \
			execution/builtins/ft_cd.c \
			execution/builtins/ft_env.c \
			execution/builtins/ft_exit.c \
			execution/builtins/ft_export.c \
			execution/builtins/ft_pwd.c \
			execution/builtins/ft_unset.c \

READLINE_LIB_IMAC = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib \
			   -I /Users/$(USER)/.brew/opt/readline/include

READLINE_LIB_MAC = -lreadline -L /usr/local/opt/readline/lib \
			   -I /usr/local/opt/readline/include

READLINE_LIB_M_MAC = -lreadline -L /opt/homebrew/opt/readline/lib \
			   -I /opt/homebrew/opt/readline/include

			   

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(P_SRCS) $(E_SRCS)
	@gcc $(FLAGS) $(READLINE_LIB_IMAC) $(P_SRCS) $(E_SRCS) -o parsing/$(NAME) -g3 -fsanitize=address

clean:
			@rm -rf *.o

fclean: 	clean
			@rm -rf $(NAME) minishell.dSYM

re: 		fclean all


parsing: $(P_SRCS)
	@gcc $(FLAGS) $(READLINE_LIB_IMAC) $(P_SRCS) -o $(NAME)

exec: 	$(E_SRCS)
		@ $(CC) $(FLAGS) -c $(E_SRCS)
		@ ar rc $(NAME) *.o
		@ $(CC) $(FLAGS) execution/main.c $(NAME) -o execution/minishell -g3 -fsanitize=address