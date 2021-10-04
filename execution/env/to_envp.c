/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:27:06 by aes-salm          #+#    #+#             */
/*   Updated: 2021/10/04 14:10:44 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char **to_envp()
{
    int i;
    char **envp;

    envp = (char**)malloc(sizeof(char *) * g_all.n_env);
    i = -1;
    printf("%d\n", g_all.n_env);
    while (++i < g_all.n_env)
    {
        envp[i] = ft_strdup(g_all.env[i].name);
        envp[i] = ft_strappend(envp[i], "=");
        envp[i] = ft_strappend(envp[i], g_all.env[i].value);
        // printf("%s\n", envp[i]);
    }
    return(envp);
}