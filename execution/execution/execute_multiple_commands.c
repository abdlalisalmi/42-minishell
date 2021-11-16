/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:33:11 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/16 13:39:48 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void    exec_sys_command(int index, char **envp)
{
    char *cmd_path;

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

void execute_child_command(int index, char** envp)
{
	pid_t pid;
	int status;

    pipe(g_all.commands[index].fd);

    pid = fork();
	if (pid < 0)
		ft__putstr_fd("Failed forking child..\n", 2);
	else if (pid == 0)
	{
		init_pipes(index);

        if (setup_redirections(g_all.commands[index]))
            return;
    
        if (is_builtins(g_all.commands[index].args[0]))
        {
            exec_builtins(g_all.commands[index].args, g_all.commands[index].n_args);
            exit(g_all.exit_code);
        }
        else
            exec_sys_command(index, envp);
	}
	else
	{
        close_pipes(index);
		waitpid(pid, &status, 0);
        printf("status : %d\n", status);
        if (status != 0)
			g_all.exit_code = 1;
        else
		    g_all.exit_code = 0;
	}
}

void execute_multiple_commands()
{
	char **envp;
    int i;

    envp = to_envp();
    i = -1;
    while (++i < g_all.n_commands)
        execute_child_command(i, envp);
    free_d_pointer(envp);
}
