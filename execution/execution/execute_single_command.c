/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:52:19 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/11 15:21:48 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void exec_system_cmd(char *cmd_path, char **args)
{
	pid_t pid;
	int status;
	char **envp;

	envp = to_envp();
	pid = fork();
	if (pid < 0)
		ft__putstr_fd("Failed forking child..\n", 2);
	else if (pid == 0)
	{
		if (execve(cmd_path, args, envp) == -1)
		{
			ft__putstr_fd(strerror(errno), 2);
			ft__putstr_fd("\n", 2);
		}
	}
	else
		waitpid(pid, &status, 0);
	free_d_pointer(envp);
}

void execute_single_command(t_commands command)
{
	char *cmd_path;
	int stdin;
	int stdout;

	save_std_fds(&stdin, &stdout);
	if (command.n_redirect != 0 && setup_redirections(command))
		return;
	if (is_builtins(command.args[0]))
	{
		exec_builtins(command.args, command.n_args);
		restore_std_fds(NONE, stdin, stdout);
	}
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
			exec_system_cmd(cmd_path, command.args);
	}
}
