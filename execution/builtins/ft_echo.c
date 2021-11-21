/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:13:35 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/21 22:30:27 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	remove_new_line_check(char *arg)
{
	int	i;

	if (arg[0] == '-' && arg[1] == '-')
		return (0);
	if (ft__strcmp(arg, "-n"))
		return (1);
	if (arg[0] == '-')
	{
		i = 0;
		while (arg[++i])
			if (arg[i] != 'n')
				return (0);
		return (1);
	}
	return (0);
}

void	ft_echo(char **args, int n_args)
{
	int	i;
	int	remove_nl;

	if (n_args == 1)
	{
		printf("\n");
		g_all.exit_code = 0;
		return ;
	}
	remove_nl = 0;
	i = 0;
	while (remove_new_line_check(args[++i]))
		remove_nl++;
	i = remove_nl + 1;
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		else
			if (!remove_nl)
				printf("\n");
		i++;
	}
	g_all.exit_code = 0;
}
