/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:27:06 by aes-salm          #+#    #+#             */
/*   Updated: 2021/10/04 21:04:22 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char **to_envp(void)
{
    int i;
    char **envp;

    envp = (char**)malloc(sizeof(char *) * g_all.n_env);
    i = -1;
    while (++i < g_all.n_env - 1)
    {
        envp[i] = ft_strdup(g_all.env[i].name);
        envp[i] = ft_strappend(envp[i], "=");
        envp[i] = ft_strappend(envp[i], g_all.env[i].value);
    }
    envp[i] = NULL;
    return(envp);
}