/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:25:31 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/14 23:35:30 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void start_execution(void)
{
	int l_cmd;
	int l_args;

    if (g_all.n_commands == 1)
		execute_single_command(g_all.commands[0]);
	else if (g_all.n_commands > 1)
		execute_multiple_commands();
	
	l_cmd = g_all.n_commands - 1;
	l_args = g_all.commands[l_cmd].n_args - 1;
	set_env("_", g_all.commands[l_cmd].args[l_args]);
}
