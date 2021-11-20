/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:27:40 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/20 16:49:41 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char	*get_env(char *name)
{
	int	i;

	if (ft__strcmp(name, "?"))
		return (ft__itoa(g_all.exit_code));
	i = 0;
	while (i < g_all.n_env)
	{
		if (ft__strcmp(name, g_all.env[i].name))
			return (ft__strdup(g_all.env[i].value));
		i++;
	}
	return (NULL);
}
