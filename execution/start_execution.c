/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:25:31 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/09 16:45:46 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void start_execution(void)
{
    if (g_all.n_commands == 1)
		execute_single_command(g_all.commands[0]);
	else
		printf("Multiple commands? Coming Soon...\n");
}