/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:25:31 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/14 21:46:37 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void start_execution(void)
{
    if (g_all.n_commands == 1)
		execute_single_command(g_all.commands[0]);
	else if (g_all.n_commands > 1)
		execute_multiple_commands();
}
