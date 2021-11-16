/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:39:09 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/16 00:41:07 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

// char *get_env_name(char *str)
// {
// 	int i;
// 	char *name;

// 	i = -1;
// 	while (str[++i] != '=')
// 	name = malloc(sizeof(char) * i);
// 	i = -1;
// 	while (str[++i] != '=')
// 		name[i] = str[i];
// 	return (name);
// }

// char *get_env_value(char *str)
// {
// 	int i;
// 	int j;
// 	char *value;

// 	i = -1;
// 	while (str[++i] != '=')
// 	value = malloc(sizeof(char) * ft__strlen(str) - i);
// 	j = 0;
// 	while (str[++i])
// 		value[j++] = str[i];
// 	value[j] = '\0';
// 	return (value);
// }

static int equal_index(char *env)
{
	int i;

	i = -1;
	while (env[++i] != '\0')
		if (env[i] == '=')
			return (i);
	return (-1);
}

static void handle_env(char *env)
{
	char *key;
	char *value;
	int eq_index;
	int env_len;

	eq_index = equal_index(env);
	env_len = ft__strlen(env);
	if (eq_index != -1)
	{
		key = ft__substr(env, 0, eq_index);
		if (eq_index != env_len)
			value = ft__substr(env, eq_index + 1, env_len - eq_index);
		else
			value = ft__strdup("");
	}
	else
	{
		key = ft__strdup(env);
		value = NULL;
	}
	set_env(key, value);
	free(key);
	free(value);
}

void	print_env(void)
{
	int i = -1;

	while (++i < g_all.n_env)
	{
		if (g_all.env[i].name && g_all.env[i].value)
			printf("declare -x %s=\"%s\"\n", g_all.env[i].name, g_all.env[i].value);
		else
			printf("declare -x %s\n", g_all.env[i].name);
	}
	g_all.exit_code = 0;
}

int ft_export(char **args, int n_args)
{
	int i;

	if (n_args == 1)
		print_env();
	else
	{
		i = 1;
		while (i < n_args)
		{
			if (ft_isdigit(args[i][0]))
			{
				ft__putstr_fd("minishell: export: `", 2);
				ft__putstr_fd(args[i], 2);
				ft__putstr_fd("': not a valid identifier\n", 2);
				g_all.exit_code = 1;
			}
			else
				handle_env(args[i]);
			i++;
		}
	}
	return (1);
}
