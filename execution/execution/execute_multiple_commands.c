/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:33:11 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/17 15:56:23 by aes-salm         ###   ########.fr       */
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
        exit(127);
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

int execute_child_command(int index, char** envp)
{
	pid_t pid;

    pipe(g_all.commands[index].fd);
    pid = fork();
	if (pid < 0)
		ft__putstr_fd("Failed forking child..\n", 2);
	else if (pid == 0)
	{
		init_pipes(index);
        if (setup_redirections(g_all.commands[index]))
            return (pid);
        if (g_all.commands[index].n_args > 0)
        {
            if (is_builtins(g_all.commands[index].args[0]))
                exec_builtins(g_all.commands[index].args, g_all.commands[index].n_args);
            else
                exec_sys_command(index, envp);
        }
        exit(g_all.exit_code);
	}
    close_pipes(index);
    return (pid);
}

void execute_multiple_commands()
{
	char **envp;
    int status;
    int pids[2048];
    int i;

    envp = to_envp();
    i = -1;
    while (++i < g_all.n_commands)
        pids[i] = execute_child_command(i, envp);
    i = -1;
    while (++i < g_all.n_commands)
    {
        waitpid(pids[i], &status, 0);
		g_all.exit_code = WEXITSTATUS(status);
    }
    free_d_pointer(envp);
}
