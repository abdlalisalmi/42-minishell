/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:24:16 by atahiri           #+#    #+#             */
/*   Updated: 2021/10/05 12:24:34 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp(char *str1, char *str2)
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
