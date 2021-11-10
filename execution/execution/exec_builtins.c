/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:36:52 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/10 22:37:14 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void exec_builtins(char **args, int n_args)
{
	if (ft__strcmp(args[0], "cd"))
		ft_cd(args, n_args);
	else if (ft__strcmp(args[0], "echo") || ft__strcmp(args[0], "ECHO"))
		ft_echo(args, n_args);
	else if (ft__strcmp(args[0], "env") || ft__strcmp(args[0], "ENV"))
		ft_env(args, n_args);
	else if (ft__strcmp(args[0], "exit"))
		ft_exit(args, n_args);
	else if (ft__strcmp(args[0], "export"))
		ft_export(args, n_args);
	else if (ft__strcmp(args[0], "pwd") || ft__strcmp(args[0], "PWD"))
		printf("%s\n", ft_pwd());
	else if (ft__strcmp(args[0], "unset"))
		ft_unset(args, n_args);
}