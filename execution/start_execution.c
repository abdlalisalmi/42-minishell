/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:25:31 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/10 13:13:40 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void start_execution(void)
{
	printf("n_commands: %d\n", g_all.n_commands);
    if (g_all.n_commands == 1)
		execute_single_command(g_all.commands[0]);
	else if (g_all.n_commands > 1)
		printf("Multiple commands? Coming Soon...\n");
}