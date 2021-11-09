/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:27:42 by aes-salm          #+#    #+#             */
/*   Updated: 2021/10/03 17:29:25 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	set_env(char *name, char *value)
{
	int i;

	i = 0;
	while (i < g_all.n_env)
	{
		if (ft_strcmp(name, g_all.env[i].name))
		{
			g_all.env[i].value = ft_strdup(value);
			return (1);
		}
		i++;
	}
	g_all.env[g_all.n_env].name = ft_strdup(name);
	g_all.env[g_all.n_env].value = ft_strdup(value);
	g_all.n_env++;
	return (1);
}
