/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:33:08 by aes-salm          #+#    #+#             */
/*   Updated: 2021/10/01 11:46:08 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char exception_args(char **args)
{
	char *old_pwd;

	if (ft_strcmp(*args, "-"))
	{
		if (!get_env("OLDPWD"))
		{
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
			set_env("?", "1");
			return (1);
		}
		else
		{
			old_pwd = get_env("OLDPWD");
			*args = ft_strdup(old_pwd);
			ft_putstr_fd(old_pwd, 2);
			ft_putstr_fd("\n", 2);
			free(old_pwd);
		}
	}
	else
		*args = ft_strdup("..");
	return (0);
}

int ft_cd(char **args, int n_args)
{
	if (n_args >= 3)
	{
		if (n_args == 3)
		{
			ft_putstr_fd("cd: string not in pwd: ", 2);
			ft_putstr_fd(args[1], 2);
			ft_putstr_fd("\n", 2);
		}
		else
			printf("cd: too many arguments\n");
		set_env("?", "1");
	}
	else
	{
		if (ft_strcmp(args[1], "-") || ft_strcmp(args[1], "--"))
			if (exception_args(&args[1]))
				return (1);
		if (chdir(args[1]) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putstr_fd(args[1], 2);
			ft_putstr_fd("\n", 2);
			set_env("?", "1");
			return (1);
		}
		set_env("OLDPWD", get_env("PWD"));
		set_env("PWD", ft_pwd());
		set_env("?", "0");
	}
	return (0);
}
