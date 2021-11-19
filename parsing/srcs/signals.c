/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:25:29 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/19 12:09:14 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	sig_handler(int sig)
{
	char	*buffer;

	if (sig == SIGINT)
	{
		buffer = ft_strdup(rl_line_buffer);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		write(2, buffer, ft_strlen(buffer));
		write(2, "  \b\b\nMINISHELL$ ", 16);
		free(buffer);
	}
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(2, "  \b\b", 4);
	}
}
