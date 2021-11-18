/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:33:08 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/18 14:11:11 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char	exception_args(char **args)
{
	char	*old_pwd;

	if (ft__strcmp(*args, "-"))
	{
		if (!get_env("OLDPWD"))
		{
			ft__putstr_fd("cd: OLDPWD not set\n", 2);
			g_all.exit_code = 1;
			return (1);
		}
		else
		{
			old_pwd = get_env("OLDPWD");
			*args = ft__strdup(old_pwd);
			ft__putstr_fd(old_pwd, 2);
			ft__putstr_fd("\n", 2);
			free(old_pwd);
		}
	}
	else
		*args = ft__strdup("..");
	return (0);
}

int	handle_cd_without_args(void)
{
	if (get_env("HOME") == NULL)
	{
		ft__putstr_fd("cd: HOME not set\n", 2);
		g_all.exit_code = 1;
		return (1);
	}
	else if (chdir(get_env("HOME")) == -1)
	{
		ft__putstr_fd("cd: ", 2);
		ft__putstr_fd(get_env("HOME"), 2);
		ft__putstr_fd(": No such file or directory\n", 2);
		g_all.exit_code = 1;
		return (1);
	}
	return (0);
}

static void	cd_too_many_args(char **args, int n_args)
{
	if (n_args == 3)
	{
		ft__putstr_fd("cd: string not in pwd: ", 2);
		ft__putstr_fd(args[1], 2);
		ft__putstr_fd("\n", 2);
	}
	else
		printf("cd: too many arguments\n");
	g_all.exit_code = 1;
}

int	ft_cd(char **args, int n_args)
{
	if (n_args >= 3)
		cd_too_many_args(args, n_args);
	else
	{
		if (n_args == 1)
			return (handle_cd_without_args());
		if (ft__strcmp(args[1], "-") || ft__strcmp(args[1], "--"))
			if (exception_args(&args[1]))
				return (1);
		if (chdir(args[1]) == -1)
		{
			ft__putstr_fd("cd: no such file or directory: ", 2);
			ft__putstr_fd(args[1], 2);
			ft__putstr_fd("\n", 2);
			g_all.exit_code = 1;
			return (1);
		}
		set_env("OLDPWD", get_env("PWD"));
		set_env("PWD", ft_pwd());
		g_all.exit_code = 0;
	}
	return (0);
}
