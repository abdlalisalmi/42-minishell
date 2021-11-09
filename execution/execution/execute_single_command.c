/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:52:19 by aes-salm          #+#    #+#             */
/*   Updated: 2021/10/05 12:33:58 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../execution.h"

int		is_builtins(char *cmd)
{
	if (ft_strcmp(cmd, "cd") || ft_strcmp(cmd, "echo") ||
		ft_strcmp(cmd, "env") || ft_strcmp(cmd, "exit") ||
		ft_strcmp(cmd, "export") || ft_strcmp(cmd, "pwd") ||
		ft_strcmp(cmd, "unset") || ft_strcmp(cmd, "ECHO"))
		return (1);
	return (0);
}

void	exec_builtins(char **args, int n_args)
{
	if (ft_strcmp(args[0], "cd"))
		ft_cd(args, n_args);
	else if (ft_strcmp(args[0], "echo") || ft_strcmp(args[0], "ECHO"))
		ft_echo(args, n_args);
	else if (ft_strcmp(args[0], "env") || ft_strcmp(args[0], "ENV"))
		ft_env(args, n_args);
	else if (ft_strcmp(args[0], "exit"))
		ft_exit(args, n_args);
	else if (ft_strcmp(args[0], "export"))
		ft_export(args, n_args);
	else if (ft_strcmp(args[0], "pwd") || ft_strcmp(args[0], "PWD"))
		printf("%s\n", ft_pwd());
	else if (ft_strcmp(args[0], "unset"))
		ft_unset(args, n_args);
}

void	exec_system_cmd(char *cmd_path, char **args)
{
	pid_t pid;
	int status;
	char **envp;

	envp = to_envp();
	pid = fork();
	if (pid < 0)
		ft_putstr_fd("Failed forking child..\n", 2);
	else if (pid == 0)
	{
		if (execve(cmd_path, args, envp) == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
		}
	}
	else
		waitpid(pid, &status, 0);
	free_d_pointer(envp);
}

int	setup_redirections(t_commands command)
{
	int i;
	int fd;

	if (command.n_redirect == 0)
		return (0);
	i = -1;
	while (++i < command.n_redirect)
	{
		if (command.redirect[i].type == RIGHT || command.redirect[i].type == DOUBLERIGHT)
		{
			if (command.redirect[i].type == RIGHT)
				fd = open(command.redirect[i].file, O_RDWR | O_CREAT | O_TRUNC, PERMISSION);
			else if (command.redirect[i].type == DOUBLERIGHT)
				fd = open(command.redirect[i].file, O_RDWR | O_CREAT | O_APPEND, PERMISSION);
			dup2(fd, 1);
			close(fd);
		}
		else if (command.redirect[i].type == LEFT)
		{
			fd = open(command.redirect[i].file, O_RDONLY, PERMISSION);
			if (fd == -1)
			{
				ft_putstr_fd("minishell: no such file or directory: ", 2);
				ft_putstr_fd(command.redirect[i].file, 2);
				ft_putstr_fd("\n", 2);
				return (1);
			}
			dup2(fd, 0);
			close(fd);
		}
	}
	return (0);
}

void	execute_single_command(t_commands command)
{
	char **paths;
	char *cmd_path;

	if (setup_redirections(command))
		return;
	if (is_builtins(command.args[0]))
		exec_builtins(command.args, command.n_args);
	else
	{
		cmd_path = get_cmd_path(command.args[0]);
		if (!cmd_path)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(command.args[0], 2);
			ft_putstr_fd(" command not found\n", 2);
		}
		else
			exec_system_cmd(cmd_path, command.args);
	}	
}
