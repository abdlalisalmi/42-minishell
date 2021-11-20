/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:33:11 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/20 13:57:02 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	exec_sys_command(int index, char **envp)
{
	char	*cmd_path;

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

int	execute_child_command_part_2(int index, pid_t pid)
{
	char	**envp;

	envp = to_envp();
	init_pipes(index);
	if (setup_redirections(g_all.commands[index]))
		return (pid);
	if (g_all.commands[index].n_args > 0)
	{
		if (is_builtins(g_all.commands[index].args[0]))
			exec_builtins(g_all.commands[index].args,
				g_all.commands[index].n_args);
		else
			exec_sys_command(index, envp);
	}
	exit(g_all.exit_code);
	return (0);
}

int	execute_child_command(int index)
{
	pid_t	pid;
	pid_t	c_pid;

	pipe(g_all.commands[index].fd);
	pid = fork();
	g_all.is_child = TRUE;
	if (pid < 0)
		ft__putstr_fd("Failed forking child..\n", 2);
	else if (pid == 0)
	{
		c_pid = execute_child_command_part_2(index, pid);
		if (c_pid != 0)
			return (c_pid);
	}
	close_pipes(index);
	return (pid);
}

void	execute_multiple_commands(void)
{
	int		status;
	int		pids[2048];
	int		i;

	i = -1;
	while (++i < g_all.n_commands)
		pids[i] = execute_child_command(i);
	i = -1;
	while (++i < g_all.n_commands)
	{
		waitpid(pids[i], &status, 0);
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
	g_all.is_child = FALSE;
}
