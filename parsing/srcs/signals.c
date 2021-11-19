/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:25:29 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/19 17:21:39 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include "../../common.h"

void	child_sig(int sig)
{
	if (sig == SIGINT)
		write(2, "\n", 1);
	if (sig == SIGQUIT)
		write(2, "Quit: 3\n", 8);
}

void	parent_sig(int sig)
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

void	sig_handler(int sig)
{
	if (g_all.is_child == 1)
		child_sig(sig);
	else
		parent_sig(sig);
}
