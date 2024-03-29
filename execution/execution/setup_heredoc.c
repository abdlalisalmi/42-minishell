/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:54:46 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/22 12:27:42 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	get_user_input(char **input, char *end)
{
	*input = readline("> ");
	if (*input != NULL && ft_strcompare(*input, end))
		return (1);
	return (0);
}

static void	handle_heredoc(int c_index, int r_index)
{
	char	*input;
	char	*filename;
	char	*fileindex;
	int		fd;

	g_all.heredoc = TRUE;
	fileindex = ft__itoa(c_index);
	filename = ft__strjoin("/tmp/__macosx__sys__kernel__", fileindex);
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	while (get_user_input(
			&input, g_all.commands[c_index].redirect[r_index].file)
		&& fd > -1)
	{
		write(fd, input, ft__strlen(input));
		write(fd, "\n", 1);
		free(input);
	}
	close(fd);
	free(g_all.commands[c_index].redirect[r_index].file);
	g_all.commands[c_index].redirect[r_index].file = filename;
	free(input);
	free(fileindex);
	if (g_all.n_commands == 0)
		free(filename);
}

void	remove_heredoc_files(void)
{
	int	i;
	int	r;

	i = -1;
	while (++i < g_all.n_commands)
	{
		r = -1;
		if (g_all.commands[i].n_redirect > 0)
			while (++r < g_all.commands[i].n_redirect)
				if (g_all.commands[i].redirect[r].type == 3)
					unlink(g_all.commands[i].redirect[r].file);
	}
	g_all.heredoc = FALSE;
}

void	setup_heredoc(void)
{
	int	i;
	int	r;

	i = -1;
	while (++i < g_all.n_commands)
	{
		r = -1;
		if (g_all.commands[i].n_redirect > 0)
		{
			while (++r < g_all.commands[i].n_redirect)
			{
				if (g_all.commands[i].redirect[r].type == 3)
					handle_heredoc(i, r);
			}
		}
	}
}
