/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:37:44 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/09 17:38:13 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	ft__strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if ((str1 == NULL && str2 != NULL) || (str2 == NULL && str1 != NULL))
		return (0);
	if (str1 == NULL && str2 == NULL)
		return (1);
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0' || str2[i] == '\0')
			break ;
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	return (0);
}
