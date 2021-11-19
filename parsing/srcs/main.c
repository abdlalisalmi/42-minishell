/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:54:21 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/19 20:29:59 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	signal_call(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}

int	main(int argc, char **argv, char **envp)
{
	char		*cmd_line;
	t_parser	*parser;
	t_tree		*tree;

	(void)argc;
	(void)argv;
	collect_env(envp);
	signal_call();
	while (1)
	{
		if (check_cmd_line(&cmd_line) == 0)
			continue ;
		add_history(cmd_line);
		parser = init_parser_lexer(cmd_line);
		tree = start_parsing(parser);
		free_parser(parser);
		if (tree != NULL)
		{
			fill_execute_struct(tree);
			start_execution();
		}
		else
			g_all.exit_code = 258;
	}
	return (0);
}
