/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:43:55 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/16 13:39:07 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	ft_isalnum(int c)
{
	if ((c > 47 && c < 58) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| c == '-' || c == '_')
		return (1);
	return (0);
}
