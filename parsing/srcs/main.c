/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:54:21 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/14 22:07:22 by atahiri          ###   ########.fr       */
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
		// free_execute_struct(tree);

		// to_print(tree);
		
	}
	return (0);
}