/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:03:15 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/09 17:38:13 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	update_env(char *name)
{
	int i;
	int index;
	
	i = -1;
	index = 0;
	while (++i < g_all.n_env)
	{
		if (!ft__strcmp(g_all.env[i].name, name))
		{
			g_all.env[index].name = g_all.env[i].name;
			g_all.env[index].value = g_all.env[i].value;
		}
		else
		{
			g_all.env[index].name = NULL;
			g_all.env[index].value = NULL;
		}
		index++;
	}
}

void	ft_unset(char **args, int n_args)
{
	int i;

	i = 0;
	while (++i < n_args)
	{
		if (ft_isdigit(args[i][0]) || ft_strchr(args[i], '='))
		{
			ft__putstr_fd("bash: unset:: `", 2);
			ft__putstr_fd(args[i], 2);
			ft__putstr_fd("': not a valid identifier\n", 2);
			set_env("?", "1");
		}
		else
		{
			update_env(args[i]);
			set_env("?", "0");
		}
	}
}