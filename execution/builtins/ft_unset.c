/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:03:15 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/22 12:12:08 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	update_env(char *name)
{
	int	i;

	i = -1;
	while (++i < g_all.n_env)
	{
		if (ft_strcompare(g_all.env[i].name, name) == 0)
		{
			free(g_all.env[i].name);
			free(g_all.env[i].value);
			while (i < g_all.n_env - 1)
			{
				g_all.env[i].name = ft__strdup(g_all.env[i + 1].name);
				g_all.env[i].value = ft__strdup(g_all.env[i + 1].value);
				i++;
				free(g_all.env[i].name);
				free(g_all.env[i].value);
			}
			g_all.n_env--;
			break ;
		}
	}
}

void	ft_unset(char **args, int n_args)
{
	int	i;

	i = 0;
	while (++i < n_args && args[i])
	{
		if (ft_isdigit(args[i][0]) || ft_strchr(args[i], '='))
		{
			ft__putstr_fd("bash: unset:: `", 2);
			ft__putstr_fd(args[i], 2);
			ft__putstr_fd("': not a valid identifier\n", 2);
			g_all.exit_code = 1;
		}
		else
		{
			update_env(args[i]);
			g_all.exit_code = 0;
		}
	}
}
