/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:25:31 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/14 23:51:02 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void handle_under_env(void)
{
	int l_cmd;
	int l_args;

	l_cmd = g_all.n_commands - 1;
	l_args = g_all.commands[l_cmd].n_args - 1;
	if (g_all.commands[l_cmd].n_args == 1
		&& ft__strcmp(g_all.commands[l_cmd].args[l_args], "env"))
		set_env("_", get_cmd_path(g_all.commands[l_cmd].args[l_args]));
	else
		set_env("_", g_all.commands[l_cmd].args[l_args]);
}

void start_execution(void)
{
	handle_under_env();
    if (g_all.n_commands == 1)
		execute_single_command(g_all.commands[0]);
	else if (g_all.n_commands > 1)
		execute_multiple_commands();
}
