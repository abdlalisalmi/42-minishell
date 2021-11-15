/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:27:38 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/16 00:10:24 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int equal_index(char *env)
{
	int i;

	i = -1;
	while (env[++i] != '\0')
		if (env[i] == '=')
			return (i);
	return (-1);
}

void handle_env(char *env, int env_index)
{
	char *key;
	char *value;
	int eq_index;
	int env_len;

	eq_index = equal_index(env);
	env_len = ft__strlen(env);
	key = ft__substr(env, 0, eq_index);
	if (env_index != env_len)
		value = ft__substr(env, eq_index + 1, env_len - eq_index);
	else
		value = ft__strdup("");
	g_all.env[env_index].name = ft__strdup(key);
	g_all.env[env_index].value = ft__strdup(value);
	free(key);
	free(value);
}

void collect_env(char **env)
{
	int i;

	g_all.env = malloc(sizeof(t_env) * 2048);
	i = -1;
	g_all.n_env = 0;
	while (env[++i] != NULL)
		handle_env(env[i], i);
	g_all.n_env = i;
}
