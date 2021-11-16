/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:03:08 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/16 13:50:44 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int check_cmd_line(char **line)
{
	*line = readline("MINISHELL$ ");
	if (line[0][0] == '\0')
	{
		free(*line);
		return (0);
	}
	return (1);
}