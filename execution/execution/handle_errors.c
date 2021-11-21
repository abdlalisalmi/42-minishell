/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:23:24 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/21 23:46:56 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	print_error(char *arg, char *message, int code)
{
	write(2, "minishell: ", 11);
	if (arg)
	{
		write(2, arg, ft__strlen(arg));
		write(2, ": ", 2);
	}
	if (message)
		write(2, message, ft__strlen(message));
	else
		write(2, strerror(errno), ft__strlen(strerror(errno)));
	write(2, "\n", 1);
	return (code);
}

void	handle_errors(char *arg, int _errno)
{
	struct stat	dir_stat;

	if (stat(arg, &dir_stat) == 0
		&& S_ISDIR(dir_stat.st_mode))
		exit(print_error(arg, "is a directory", 126));
	if (_errno == 13)
		exit(print_error(arg, NULL, 126));
	else if (_errno == 8)
		exit(print_error(arg, NULL, 1));
	else
		exit(print_error(arg, "command not found", 127));
}
