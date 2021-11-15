/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:42:59 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/12 01:46:45 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	*ft_realloc(void *old_alloc, size_t old_size, size_t new_size)
{
	unsigned char	*old_alloc_t;
	unsigned char	*new_alloc;
	size_t			i;

	i = 0;
	if (old_alloc == NULL)
		return (malloc(new_size));
	old_alloc_t = (unsigned char *)old_alloc;
	new_alloc = (unsigned char *)malloc(new_size);
	if (new_alloc == NULL)
		return (NULL);
	while (i < old_size && i < new_size)
	{
		new_alloc[i] = old_alloc_t[i];
		i++;
	}
	free(old_alloc);
	return (new_alloc);
}


void	*realloc_edited(void *old_alloc, size_t count, size_t old_size)
{
	void	*new_allo;

	new_allo = ft_realloc(old_alloc, count * old_size, count * (old_size + 1));
	return (new_allo);
}