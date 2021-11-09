/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:07:23 by aes-salm          #+#    #+#             */
/*   Updated: 2021/10/01 11:46:08 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char *ft_pwd(void)
{
	char pwd[4096];

	if (!getcwd(pwd, 2048))
		return (NULL);
	set_env("?", "0");
	return (ft_strdup(pwd));
}