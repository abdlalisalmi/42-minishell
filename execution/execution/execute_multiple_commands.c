/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:33:11 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/10 23:58:20 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void command_execute(int index, t_commands command, char** envp)
{
	pid_t pid;
	int status;
    char *cmd_path;

	// init pipe --> pipe(node->fd);
    pipe(command.fd);
	
    printf("Command: %s", command.args[0]);
    pid = fork();
	if (pid < 0)
		ft__putstr_fd("Failed forking child..\n", 2);
	else if (pid == 0)
	{
		// if (index == 0)
        //     close(command.fd[PIPE_OUT]);
		if (index < g_all.n_commands - 1)
			dup2(command.fd[PIPE_IN], FILE_D_OUT);
        if (index > 0)
            dup2(g_all.commands[index - 1].fd[PIPE_OUT], FILE_D_IN);

        // if (command.n_redirect != 0 && setup_redirections(command))
        //     	return;
        if (is_builtins(command.args[0]))
            exec_builtins(command.args, command.n_args);
        else
        {
            cmd_path = get_cmd_path(command.args[0]);
            if (!cmd_path)
            {
                ft__putstr_fd("minishell: ", 2);
                ft__putstr_fd(command.args[0], 2);
                ft__putstr_fd(" command not found\n", 2);
            }
            else
            {
                if (execve(cmd_path, command.args, envp) == -1)
                {
                    ft__putstr_fd(strerror(errno), 2);
                    ft__putstr_fd("\n", 2);
                }
            }
        }

	}
	else
	{
        if (index < g_all.n_commands - 1)
			close(command.fd[PIPE_IN]);
        if (index > 0)
            close(g_all.commands[index - 1].fd[PIPE_OUT]);
        // if (index == g_all.n_commands - 1)
        //     close()
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
        command_execute(i, g_all.commands[i], envp);
    free_d_pointer(envp);
    // i = -1;
    // while (++i < g_all.n_commands)
    // {
    //     close(g_all.commands[i].fd[0]);
    //     close(g_all.commands[i].fd[1]);
    // }
}
