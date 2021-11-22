/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:33:08 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/22 01:29:44 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	handle_cd_without_args(void)
{
	char	*home;

	home = get_env("HOME");
	if (home == NULL)
	{
		ft__putstr_fd("cd: HOME not set\n", 2);
		g_all.exit_code = 1;
		free(home);
		return (1);
	}
	else if (chdir(home) == -1)
	{
		ft__putstr_fd("cd: ", 2);
		ft__putstr_fd(home, 2);
		ft__putstr_fd(": No such file or directory\n", 2);
		g_all.exit_code = 1;
		free(home);
		return (1);
	}
	free(home);
	return (0);
}

int	ft_cd(char **args, int n_args)
{
	char	*pwd;

	if (n_args == 1)
		return (handle_cd_without_args());
	pwd = ft_pwd();
	if (chdir(args[1]) == -1)
	{
		ft__putstr_fd("cd: no such file or directory: ", 2);
		ft__putstr_fd(args[1], 2);
		ft__putstr_fd("\n", 2);
		g_all.exit_code = 1;
		free(pwd);
		return (1);
	}
	set_env("OLDPWD", pwd);
	free(pwd);
	pwd = ft_pwd();
	set_env("PWD", pwd);
	free(pwd);
	g_all.exit_code = 0;
	return (0);
}
