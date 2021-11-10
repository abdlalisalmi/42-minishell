/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:49:49 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/10 12:47:04 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void save_redirection(int command_index, char *command)
{
	int i = -1;
	char **space_split;
	g_all.commands[command_index].redirect = malloc(sizeof(t_redirect) * g_all.commands[command_index].n_redirect);

	space_split = ft_split(command, ' ');

	while (space_split[++i])
	{
		if (ft_strcmp(space_split[i], ">"))
		{
			g_all.commands[command_index].redirect->type = RIGHT;
			g_all.commands[command_index].redirect->file = space_split[i + 1];
		}
		else if (ft_strcmp(space_split[i], "<"))
		{
			g_all.commands[command_index].redirect->type = LEFT;
			g_all.commands[command_index].redirect->file = space_split[i + 1];
		}
		else if (ft_strcmp(space_split[i], ">>"))
		{
			g_all.commands[command_index].redirect->type = DOUBLERIGHT;
			g_all.commands[command_index].redirect->file = space_split[i + 1];
		}
	}
}

int count_number_of_redirections(char *command)
{
	int i = -1;
	int nb = 0;
	char **space_split;

	space_split = ft_split(command, ' ');

	while (space_split[++i])
	{
		if (ft_strcmp(space_split[i], ">") || ft_strcmp(space_split[i], ">>") || ft_strcmp(space_split[i], "<"))
		{
			nb++;
		}
	}
	return nb;
}

void parsing_redirections(char **commands, int nb_command)
{
	int i = -1;

	while (++i < nb_command)
	{
		g_all.commands[i].n_redirect = count_number_of_redirections(commands[i]);
		if (g_all.commands[i].n_redirect > 0)
		{
			save_redirection(i, commands[i]);
			// dprintf(2, "GGG ========= %s\n", g_all.commands[i].redirect->file);
		}
		// dprintf(2, "NB ========= %d\n", g_all.commands[i].n_redirect);
	}
}

int number_of_pipes(char *buff)
{
	int i = -1;
	int nb = 0;
	while (buff[++i])
		if (buff[i] == '|')
			nb++;
	return nb;
}

char **split_by_pipe(char *buff)
{
	char **splitted;
	int nb;

	nb = number_of_pipes(buff);
	splitted = ft_split(buff, '|');
	return splitted;
}

char *remove_whitespaces(char *buff)
{
	char *trimmed;
	trimmed = trim_spaces(buff);
	return trimmed;
}

int count_number_of_args(char **str)
{
	int i = -1;
	int count = 0;
	while (str[++i] != NULL)
	{
		count++;
	}
	return count;
}

int collect_and_check_cmd_line(char **cmd_line)
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

void start_parsing(char *line)
{
	char *trimed;
	char **split;
	char **trim_commands;
	int nb;

	trimed = trim_spaces(line);
	if (verif_quotes(trimed) == -1)
		ft_putstr_fd("Error : quote not closed\n", 2);
	if (starts_with(trimed) || check_semicolon(trimed))
		return;
	split = split_by_pipe(trimed);
	nb = ft_dplen(split);
	trim_commands = malloc(sizeof(char *) * (nb + 1));
	// printf("|%s|\n", trimed);
	int i = -1;
	while (++i < nb)
		trim_commands[i] = remove_whitespaces(split[i]);
	trim_commands[i] = NULL;
	int nb_command = count_number_of_args(trim_commands);
	g_all.commands = malloc(sizeof(t_commands) * nb_command);

	parsing_redirections(trim_commands, nb_command);

	i = -1;
	int j = 0;
	while (++i < nb_command)
	{
		char **split_spaces = ft_split(trim_commands[i], ' ');
		int count = count_number_of_args(split_spaces);
		g_all.commands[i].n_args = count;
		g_all.commands[i].args = (char **)malloc(sizeof(char *) * (count + 1));
		j = 0;
		while (j < count)
		{
			g_all.commands[i].args[j] = ft_strdup(split_spaces[j]);
			j++;
		}
		g_all.commands[i].args[j] = NULL;
	}
	// print_out(g_all.commands[0].args);
	// printf("\n%s\n", g_all.commands[0].redirect[0].file);

	// printf("number of redirections command 1: %d\n", g_all.commands[0].n_redirect);
	// printf("number of redirections command 2: %d\n", g_all.commands[1].n_redirect);
	// printf("|%d|\n", nb);
}

int main(int argc, char **argv, char **envp)
{
	char *cmd_line;

	(void)argc;
	(void)argv;
	(void)envp;
	collect_env(envp);
	while (1)
	{
		if (collect_and_check_cmd_line(&cmd_line) == 0)
			continue;
		add_history(cmd_line);
		start_parsing(cmd_line);
		
	}
	return (0);
}