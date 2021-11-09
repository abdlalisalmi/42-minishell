/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:27:40 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/09 17:38:13 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char *get_env(char *name)
{
	int i;

	i = 0;
	while (i < g_all.n_env)
	{
		if (ft__strcmp(name, g_all.env[i].name))
			return (g_all.env[i].value);
		i++;
	}
	return (NULL);
}
