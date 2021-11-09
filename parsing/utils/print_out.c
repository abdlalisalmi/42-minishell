/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:42:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/10/04 12:42:22 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		print_out(char **to_print)
{
	int j = 0;
	while (to_print[j] != '\0')
	{
		write(1, to_print[j], ft_strlen(to_print[j]));
		write(1, "\n", 1);
		j++;
	}
}