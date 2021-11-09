/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:27:38 by aes-salm          #+#    #+#             */
/*   Updated: 2021/10/03 17:30:18 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void collect_env(char **env)
{
	int i;

	g_all.env = malloc(sizeof(t_env) * 1024);
	i = 0;
	g_all.n_env = 0;
	while (*env++ != 0)
	{
		g_all.env[i].name = ft_split(*env, '=')[0];
		g_all.env[i].value = ft_split(*env, '=')[1];
		g_all.n_env++;
		i++;
	}
}
