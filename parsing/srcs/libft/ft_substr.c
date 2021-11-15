/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:53:12 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/11 22:55:40 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;
	size_t	lens;

	count = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen((char *)s);
	if (start > lens)
		len = 0;
	str = malloc((len + 1 * sizeof(char)));
	if (!str)
		return (NULL);
	while (count < len && s[start] && start < lens)
	{
		str[count] = *(unsigned char *)(s + start);
		start++;
		count++;
	}
	str[count] = '\0';
	return (str);
}