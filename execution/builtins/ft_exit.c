/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:20:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/18 14:13:30 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

long long	get_number(const char *str, int i)
{
	long long	code;

	code = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') || i > 10)
			return (9223372036854775809U);
		code = code * 10;
		code += (int)str[i] - '0';
		i++;
	}
	return (code);
}

static long long	get_exit_code(const char *str)
{
	long long	code;
	int			sign;
	int			i;

	code = 0;
	sign = 0;
	i = 0;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	code = get_number(str, i);
	if ((code > LONG_MAX && sign == 0)
		|| (code > LONG_MIN && sign == 1))
		return (9223372036854775809U);
	if (sign == 1)
		return (-code);
	else
		return (code);
}

void	ft_exit(char **args, int n_args)
{
	unsigned long	code;

	if (n_args == 1)
		exit(EXIT_SUCCESS);
	else if (n_args >= 2)
	{
		code = get_exit_code(args[1]);
		if (code == 9223372036854775809U)
		{
			write(2, "exit\n", 5);
			write(2, "minishell: exit: ", 17);
			write(2, args[1], ft__strlen(args[1]));
			write(2, ": numeric argument required\n", 28);
			exit(255);
		}
		else if (n_args >= 3)
			write(2, "minishell: exit: too many arguments\n", 36);
		else
		{
			write(2, "exit\n", 5);
			exit(code);
		}
	}
}
