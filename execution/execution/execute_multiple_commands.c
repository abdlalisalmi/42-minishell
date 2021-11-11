/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:33:11 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/11 12:35:27 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void command_execute(int index, char** envp)
{
	pid_t pid;
	int status;
    char *cmd_path;

    pipe(g_all.commands[index].fd);

    pid = fork();
	if (pid < 0)
		ft__putstr_fd("Failed forking child..\n", 2);
	else if (pid == 0)
	{

		if (index == 0)
        {
            printf("FIRST\n");
            dup2(g_all.commands[index].fd[1], 1);
            close(g_all.commands[index].fd[0]);
        }
        else if (index == g_all.n_commands - 1)
        {
            printf("LAST\n");
            dup2(g_all.commands[index - 1].fd[0], 0);
            close(g_all.commands[index].fd[0]);
            close(g_all.commands[index].fd[1]);
        }
        else
        {
            printf("MIDDLE\n");
            dup2(g_all.commands[index].fd[1], 1);
            dup2(g_all.commands[index - 1].fd[0], 0);
            close(g_all.commands[index].fd[0]);
        }

        // if (command.n_redirect != 0 && setup_redirections(command))
        //     	return;
    
        if (is_builtins(g_all.commands[index].args[0]))
            exec_builtins(g_all.commands[index].args, g_all.commands[index].n_args);
        else
        {
            cmd_path = get_cmd_path(g_all.commands[index].args[0]);
            if (!cmd_path)
            {
                ft__putstr_fd("minishell: ", 2);
                ft__putstr_fd(g_all.commands[index].args[0], 2);
                ft__putstr_fd(" command not found\n", 2);
            }
            else
            {
                if (execve(cmd_path, g_all.commands[index].args, envp) == -1)
                {
                    ft__putstr_fd(strerror(errno), 2);
                    ft__putstr_fd("\n", 2);
                }
            }
        }

	}
	else
	{
        if (index == 0)
        {
            printf("P FIRST\n");
            close(g_all.commands[index].fd[1]);
        }
        else if (index == g_all.n_commands - 1)
        {
            printf("P LAST\n");
            close(g_all.commands[index - 1].fd[0]);
            close(g_all.commands[index - 1].fd[1]);
            close(g_all.commands[index].fd[0]);
            close(g_all.commands[index].fd[1]);
        }
        else
        {
            printf("P MIDDLE\n");
            close(g_all.commands[index - 1].fd[0]);
            close(g_all.commands[index].fd[1]);
        }
		waitpid(pid, &status, 0);
	}

	
}

void execute_multiple_commands()
{
	char **envp;
    int i;

    envp = to_envp();
    i = -1;
    while (++i < g_all.n_commands)
        command_execute(i, envp);
    free_d_pointer(envp);
    while(1);
    // i = -1;
    // while (++i < g_all.n_commands)
    // {
    //     close(g_all.commands[i].fd[0]);
    //     close(g_all.commands[i].fd[1]);
    // }
}
