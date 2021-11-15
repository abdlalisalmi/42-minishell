/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:25:31 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/15 16:01:23 by aes-salm         ###   ########.fr       */
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

void free_execution_struct(void)
{
	int i;
	int r;

	i = -1;
	while (++i < g_all.n_commands)
	{
		free_d_pointer(g_all.commands[i].args);
		r = -1;
		if (g_all.commands[i].n_redirect > 0)
		{
			while (++r < g_all.commands[i].n_redirect)
				free(g_all.commands[i].redirect[r].file);
			free(g_all.commands[i].redirect);
		}
		free(g_all.commands);
	}
}

void start_execution(void)
{
	handle_under_env();
    if (g_all.n_commands == 1)
		execute_single_command(g_all.commands[0]);
	else if (g_all.n_commands > 1)
		execute_multiple_commands();
	free_execution_struct();
}
