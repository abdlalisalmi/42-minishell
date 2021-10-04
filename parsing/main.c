/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:49:49 by atahiri           #+#    #+#             */
/*   Updated: 2021/10/04 11:49:04 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	collect_and_check_cmd_line(char **cmd_line)
{
	*cmd_line = readline("MINISHELL$ ");
	if (*cmd_line == NULL)
	{
		write(2, "\033[MINISHELL$ exit\n", 19);
		exit(0);
	}
	if (cmd_line[0][0] == '\0')
	{
		free(*cmd_line);
		return (0);
	}
	return (1);
}

void	start_parsing(char *line)
{
	char *trimed;

	trimed = trim_spaces(line);
	printf("|%s|\n", trimed);
}

int	main(int argc, char **argv, char **envp)
{
	char		*cmd_line;

	(void)argc;
	(void)argv;
	(void)envp;
	// collect_env(envp);
	while (1)
	{
		if (collect_and_check_cmd_line(&cmd_line) == 0)
			continue;
		add_history(cmd_line);
		start_parsing(cmd_line);
	}
	return (0);
}