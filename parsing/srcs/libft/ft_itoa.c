/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:47:36 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/11 23:47:47 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static int	numb(int nb)
{
	if (nb == 0)
		return (1);
	return (1 + numb(nb / 10));
}

static char	*affect(char *s, int num, int i)
{
	unsigned int	l;

	l = 0;
	if (num == 0)
		*s = num + 48;
	else if (num < 0)
	{
		*s = '-';
		l = num * (-1);
	}
	else
		l = num;
	s[i + 1] = '\0';
	while (l != 0)
	{
		s[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dst;

	if (n > 0)
		len = numb(n) - 1;
	else
		len = numb(n);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	return (affect(dst, n, len - 1));
}
