/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:34:18 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/19 17:33:13 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	is_builtins(char *cmd)
{
	if (ft__strcmp(cmd, "cd") || ft__strcmp(cmd, "echo")
		|| ft__strcmp(cmd, "env") || ft__strcmp(cmd, "exit")
		|| ft__strcmp(cmd, "export") || ft__strcmp(cmd, "pwd")
		|| ft__strcmp(cmd, "unset") || ft__strcmp(cmd, "ECHO"))
		return (1);
	return (0);
}
