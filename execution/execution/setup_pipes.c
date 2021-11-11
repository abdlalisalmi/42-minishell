/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:38:14 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/11 15:42:08 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../execution.h"

void init_pipes(int index)
{
    if (index == 0)
    {
        dup2(g_all.commands[index].fd[1], 1);
        close(g_all.commands[index].fd[0]);
    }
    else if (index == g_all.n_commands - 1)
    {
        dup2(g_all.commands[index - 1].fd[0], 0);
        close(g_all.commands[index].fd[0]);
        close(g_all.commands[index].fd[1]);
    }
    else
    {
        dup2(g_all.commands[index].fd[1], 1);
        dup2(g_all.commands[index - 1].fd[0], 0);
        close(g_all.commands[index].fd[0]);
    }
}

void close_pipes(int index)
{
    if (index == 0)
        close(g_all.commands[index].fd[1]);
    else if (index == g_all.n_commands - 1)
    {
        close(g_all.commands[index - 1].fd[0]);
        close(g_all.commands[index - 1].fd[1]);
        close(g_all.commands[index].fd[0]);
        close(g_all.commands[index].fd[1]);
    }
    else
    {
        close(g_all.commands[index - 1].fd[0]);
        close(g_all.commands[index].fd[1]);
    }
}
