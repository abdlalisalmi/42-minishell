/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:39:09 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/09 17:38:13 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char *get_env_name(char *str)
{
	int i;
	char *name;

	i = -1;
	while (str[++i] != '=')
	name = malloc(sizeof(char) * i);
	i = -1;
	while (str[++i] != '=')
		name[i] = str[i];
	return (name);
}

char *get_env_value(char *str)
{
	int i;
	int j;
	char *value;

	i = -1;
	while (str[++i] != '=')
	value = malloc(sizeof(char) * ft__strlen(str) - i);
	j = 0;
	while (str[++i])
		value[j++] = str[i];
	value[j] = '\0';
	return (value);
}

void	print_env(void)
{
	int i = -1;

	while (++i < g_all.n_env)
	{
		if (g_all.env[i].name && !ft__strcmp(g_all.env[i].name, "?"))
			printf("declare -x %s=\"%s\"\n", g_all.env[i].name, g_all.env[i].value);
	}
	set_env("?", "0");
}

int ft_export(char **args, int n_args)
{
	int i;

	if (n_args == 1)
		print_env();
	else
	{
		i = 0;
		while (i < n_args)
		{
			if (ft_isdigit(args[i][0]))
			{
				ft__putstr_fd("minishell: export: `", 2);
				ft__putstr_fd(args[i], 2);
				ft__putstr_fd("': not a valid identifier\n", 2);
				set_env("?", "1");
			}
			else
				if (ft_strchr(args[i], '='))
				{
					set_env(get_env_name(args[i]), get_env_value(args[i]));
					set_env("?", "0");
				}
			i++;
		}
	}
	return (1);
}
