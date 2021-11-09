/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:07:46 by aes-salm          #+#    #+#             */
/*   Updated: 2021/10/01 11:46:08 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void ft_env(char **args, int n_args)
{
	int i;

	if (n_args > 1)
	{
		write(2, "env: ", 6);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": No such file or directory\n", 28);
		set_env("?", "127");
	}
	else
	{
		i = -1;
		while (++i < g_all.n_env)
			if (g_all.env[i].name && !ft_strcmp(g_all.env[i].name, "?"))
				printf("%s=%s\n", g_all.env[i].name, g_all.env[i].value);
		set_env("?", "0");
	}
}