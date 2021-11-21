/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:03:08 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/21 22:50:22 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	check_cmd_line(char **line)
{
	*line = readline("MINISHELL$ ");
	if (*line == NULL)
	{
		write(2, "\033MMINISHELL$ exit\n", 18);
		exit(g_all.exit_code);
	}
	if (ft_isspace(*line))
	{
		free(*line);
		return (0);
	}
	if (line[0][0] == '\0')
	{
		free(*line);
		return (0);
	}
	return (1);
}
