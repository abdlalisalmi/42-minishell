NAME = 		minishell

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

INCLUDES =	common.h \
			execution/execution.h \
			parsing/includes/main.h \
			parsing/includes/tokenizer.h \
			parsing/includes/lexer.h \
			parsing/includes/parser.h \
			parsing/includes/tree.h \

READLINE_LIB_IMAC = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib \
			   -I /Users/$(USER)/.brew/opt/readline/include

READLINE_LIB_MAC = -lreadline -L /usr/local/opt/readline/lib \
			   -I /usr/local/opt/readline/include

READLINE_LIB_M_MAC = -lreadline -L /opt/homebrew/opt/readline/lib \
			   -I /opt/homebrew/opt/readline/include

P_SRCS 	= 	parsing/srcs/main.c \
			parsing/srcs/readline.c \
			parsing/srcs/lexer.c \
			parsing/srcs/parser.c \
			parsing/srcs/put_error.c \
			parsing/srcs/token.c \
			parsing/srcs/collect_others.c \
			parsing/srcs/lexer_utils.c \
			parsing/srcs/collect_double_quotes.c \
			parsing/srcs/collect_env.c \
			parsing/srcs/parser_utils.c \
			parsing/srcs/init_tree.c \
			parsing/srcs/parser_single_command.c \
			parsing/srcs/parser_pipeline.c \
			parsing/srcs/to_print.c \
			parsing/srcs/freeing.c \
			parsing/srcs/parser_check_errors.c \
			parsing/srcs/fill_execute_struct.c \
			parsing/srcs/collect_env_inline.c \
			parsing/srcs/signals.c \
			parsing/srcs/libft/ft_strlen.c \
			parsing/srcs/libft/ft_strdup.c \
			parsing/srcs/libft/ft_substr.c \
			parsing/srcs/libft/ft_strjoin.c \
			parsing/srcs/libft/ft_strjoin_char.c \
			parsing/srcs/libft/ft_num_words.c \
			parsing/srcs/libft/ft_isalnum.c \
			parsing/srcs/libft/ft_isalpha.c \
			parsing/srcs/libft/ft_itoa.c \
			parsing/srcs/libft/ft_realloc.c \
			
E_SRCS 	=	execution/start_execution.c \
			execution/execution/execute_single_command.c \
			execution/execution/execute_multiple_commands.c \
			execution/execution/is_builtins.c \
			execution/execution/exec_builtins.c \
			execution/execution/setup_pipes.c \
			execution/execution/setup_redirections.c \
			execution/execution/setup_heredoc.c \
			execution/utils/free_d_pointer.c \
			execution/utils/get_cmd_path.c \
			execution/env/collect_env.c \
			execution/env/get_env.c \
			execution/env/set_env.c \
			execution/env/to_envp.c \
			execution/env/sort_env.c \
			execution/functions/ft_strlen.c \
			execution/functions/ft_strjoin.c \
			execution/functions/ft_putstr_fd.c \
			execution/functions/ft_memcopy.c \
			execution/functions/ft_strcmp.c \
			execution/functions/ft_strdup.c \
			execution/functions/ft_strchr.c \
			execution/functions/ft_isdigit.c \
			execution/functions/ft_strappend.c \
			execution/functions/ft_split.c \
			execution/functions/ft_itoa.c \
			execution/functions/ft_substr.c \
			execution/functions/ft_strcompare.c \
			execution/builtins/ft_echo.c \
			execution/builtins/ft_cd.c \
			execution/builtins/ft_env.c \
			execution/builtins/ft_exit.c \
			execution/builtins/ft_export.c \
			execution/builtins/ft_pwd.c \
			execution/builtins/ft_unset.c \

all: $(NAME)

$(NAME): $(P_SRCS) $(E_SRCS) $(INCLUDES)
	@gcc $(FLAGS) $(READLINE_LIB_MAC) $(P_SRCS) $(E_SRCS) -o minishell 

clean:
			@rm -rf *.o 

fclean: 	clean
			@rm -rf $(NAME) $(NAME).dSYM $(NAME).a
			@rm -rf execution/$(NAME) execution/$(NAME).dSYM
			@rm -rf parsing/$(NAME).dSYM parsing/$(NAME) 

re: 		fclean all