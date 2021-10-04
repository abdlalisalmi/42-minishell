/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:52:19 by aes-salm          #+#    #+#             */
/*   Updated: 2021/10/04 12:07:08 by aes-salm         ###   ########.fr       */
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

void	exec_system_cmd(char *cmd_path, char **args, char **envp)
{
	pid_t pid;
	int status;

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
	{
		waitpid(pid, &status, 0);
		printf("status = %d\n", status);
	}
}

// void	setup_redirections(t_command command)
// {
// 	int i;
// 	int fd;

// 	i = -1;
// 	while (++i < command.n_red)
// 	{
// 		printf("%s\n", command.redirect[0].file);
// 	}
	
// 	// if (command.r_right == 1 || command.r_right == 2)
// 	// {
// 	// 	i = -1;
// 	// 	while (command.outfile[++i] && command.r_right == 1)
// 	// 		fd = open(command.outfile[i], O_WRONLY | O_CREAT | O_TRUNC, PERMISSION);
// 	// 	i = -1;
// 	// 	while (command.outfile[++i] && command.r_right == 2)
// 	// 		fd = open(command.outfile[i], O_WRONLY | O_CREAT, PERMISSION);
// 	// 	dup2(fd, 1);
// 	// 	close(fd);
// 	// }
// 	// if (command.r_left == 1)
// 	// {
// 	// 	// printf("Input file redirections");
// 	// }
// }

void	execute_single_command(t_commands command, char **envp)
{
	char **paths;
	char *cmd_path;

	// setup_redirections(command);
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
			exec_system_cmd(cmd_path, command.args, envp);
	}	
}
