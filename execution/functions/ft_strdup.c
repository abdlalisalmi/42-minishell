/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:51:10 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/16 00:37:40 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char	*ft__strdup(const char *str)
{
	char			*ptr;
	unsigned int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	if (!(ptr = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}