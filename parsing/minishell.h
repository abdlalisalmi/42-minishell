/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:59:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/10/01 12:01:06 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define COLORSTART "\e[38;5;226m"
# define NEWLINE "\e[1m\e[38;5;82m$> \e[0m"
# define COLOREND "\e[0m"
# define STRERRORCOLOR "\e[38;5;196m"

typedef struct s_all
{
	int			quote;
	int			d_quote;
	char		*buff;
	int 		nb_semicolons;
	int			nb_pipes;

}				t_all;

t_all	g_all;

#endif