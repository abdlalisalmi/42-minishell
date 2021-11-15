/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:59:55 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/15 21:39:03 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void save_std_fds(int *stdin, int *stdout)
{
	*stdin = dup(0);
	*stdout = dup(1);
}

void restore_std_fds(int type, int stdin, int stdout)
{
	if (type == RIGHT || type == DOUBLERIGHT || type == NONE)
		dup2(stdout, 1);
	if (type == LEFT || type == HEREDOC || type == NONE)
		dup2(stdin, 0);
}

int setup_redirections(t_commands command)
{
	int i;
	int fd;
	int stdin;
	int stdout;

	save_std_fds(&stdin, &stdout);
	i = -1;
	while (++i < command.n_redirect)
	{
		restore_std_fds(command.redirect[i].type, stdin, stdout);
		if (command.redirect[i].type == RIGHT || command.redirect[i].type == DOUBLERIGHT)
		{
			if (command.redirect[i].type == RIGHT)
				fd = open(command.redirect[i].file, O_RDWR | O_CREAT | O_TRUNC, PERMISSION);
			else if (command.redirect[i].type == DOUBLERIGHT)
				fd = open(command.redirect[i].file, O_RDWR | O_CREAT | O_APPEND, PERMISSION);
			if (fd == -1)
			{
				ft__putstr_fd(strerror(errno), 2);
				ft__putstr_fd("\n", 2);
				return (1);
			}
			dup2(fd, 1);
			close(fd);
		}
		else if (command.redirect[i].type == LEFT)
		{
			fd = open(command.redirect[i].file, O_RDONLY, PERMISSION);
			if (fd == -1)
			{
				ft__putstr_fd(strerror(errno), 2);
				ft__putstr_fd("\n", 2);
				return (1);
			}
			dup2(fd, 0);
			close(fd);
		}
	}
	return (0);
}`