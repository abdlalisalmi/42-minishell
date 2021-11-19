/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:27:51 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/19 11:58:46 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	ft_isspace(char *str)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	while (++i < ft_strlen(str))
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r'
			|| str[i] == ' ')
			nb++;
	}
	if (nb == ft_strlen(str))
		return (1);
	return (0);
}
