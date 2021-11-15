/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:54:21 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/15 16:29:15 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int main(int argc, char **argv, char **envp)
{
	char		*cmd_line;
	t_parser	*parser;
	t_tree		*tree;
	
	(void)argc;
	(void)argv;
	collect_env(envp);
	while(1)
	{
		if (check_cmd_line(&cmd_line) == 0)
			continue;
		add_history(cmd_line);
		parser = init_parser_lexer(cmd_line);
		tree = start_parsing(parser);
		free_parser(parser);

		fill_execute_struct(tree);
		start_execution();
		
		// system("leaks minishell");
		// free_execute_struct(tree);

		// to_print(tree);
		
	}
	return (0);
}