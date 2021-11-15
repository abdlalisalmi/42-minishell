/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:27:38 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/15 21:55:28 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int is_contain_value(char *env)
{
	int i;

	i = -1;
	while (env[++i] != '\0')
		if (env[i] == '=')
			return (1);
	return (0);
}

void collect_env(char **env)
{
	int i;

	g_all.env = malloc(sizeof(t_env) * 2048);
	i = 0;
	g_all.n_env = 0;
	while (*env++ != NULL)
	{
		if (*env != NULL)
		{
			g_all.env[i].name = ft__split(*env, '=')[0];
			if (is_contain_value(*env))
				g_all.env[i].value = ft__split(*env, '=')[1];
			g_all.n_env++;
		}
		i++;
	}
}
