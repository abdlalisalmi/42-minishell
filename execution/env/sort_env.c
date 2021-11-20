/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:50:47 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/20 16:29:21 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

static void	swap_key_value(int index)
{
	char	*tmp;

	tmp = ft__strdup(g_all.env[index].name);
	free(g_all.env[index].name);
	g_all.env[index].name = ft__strdup(g_all.env[index + 1].name);
	free(g_all.env[index + 1].name);
	g_all.env[index + 1].name = ft__strdup(tmp);
	free(tmp);
	tmp = ft__strdup(g_all.env[index].value);
	free(g_all.env[index].value);
	g_all.env[index].value = ft__strdup(g_all.env[index + 1].value);
	free(g_all.env[index + 1].value);
	g_all.env[index + 1].value = ft__strdup(tmp);
	free(tmp);
}

void	sort_env(void)
{
	int	i;
	int	find;

	find = 1;
	while (find)
	{
		i = -1;
		find = 0;
		while (++i < g_all.n_env - 1)
		{
			if (ft_strcompare(g_all.env[i].name, g_all.env[i + 1].name) > 0)
			{
				swap_key_value(i);
				find = 1;
			}
		}
	}
}
