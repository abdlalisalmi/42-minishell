/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:52:19 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/22 01:13:22 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	set_exit_code(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			g_all.exit_code = 130;
		else if (WTERMSIG(status) == SIGQUIT)
			g_all.exit_code = 131;
	}
	else
		g_all.exit_code = WEXITSTATUS(status);
}

void	exec_system_cmd(t_commands command)
{
	pid_t	pid;
	int		status;
	char	**envp;
	char	*cmd_path;

	envp = NULL;
	pid = fork();
	g_all.is_child = TRUE;
	if (pid < 0)
		ft__putstr_fd("Failed forking child..\n", 2);
	else if (pid == 0)
	{
		envp = to_envp();
		cmd_path = get_cmd_path(command.args[0]);
		execve(cmd_path, command.args, envp);
		handle_errors(command.args[0], errno);
	}
	else
	{
		waitpid(pid, &status, 0);
		g_all.is_child = FALSE;
		set_exit_code(status);
	}
}

void	execute_single_command(t_commands command)
{
	int		stdin;
	int		stdout;

	save_std_fds(&stdin, &stdout);
	if ((command.n_redirect > 0 && setup_redirections(command))
		|| command.n_args == 0)
	{
		restore_std_fds(NONE, stdin, stdout);
		return ;
	}
	if (is_builtins(command.args[0]))
		exec_builtins(command.args, command.n_args);
	else
		exec_system_cmd(command);
	restore_std_fds(NONE, stdin, stdout);
}
