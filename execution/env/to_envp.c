/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:27:06 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/19 19:45:51 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char	**to_envp(void)
{
	int		i;
	char	**envp;
	char	*tmp;

	envp = (char **)malloc(sizeof(char *) * g_all.n_env);
	i = -1;
	while (++i < g_all.n_env - 1)
	{
		envp[i] = ft__strdup(g_all.env[i].name);
		tmp = ft__strdup(envp[i]);
		free(envp[i]);
		envp[i] = ft_strappend(tmp, "=");
		free(tmp);
		tmp = ft__strdup(envp[i]);
		envp[i] = ft_strappend(tmp, g_all.env[i].value);
		free(tmp);
	}
	envp[i] = NULL;
	return (envp);
}
