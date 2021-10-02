/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:59:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/10/02 12:22:41 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* strerror() and printf() function */
# include <stdio.h>

/* GNU Readline Library */
# include <readline/readline.h>
# include <readline/history.h>

/* signal() and kill() system call functions */
# include <signal.h>

/* open() function */
# include <fcntl.h>

/* read() and write() and close() functions */
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/* malloc() and free() exit() function */
# include <stdlib.h>

/* errno external variable */
# include <sys/errno.h>

# include <string.h>
# include <sys/stat.h>


# define COLORSTART "\e[38;5;226m"
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