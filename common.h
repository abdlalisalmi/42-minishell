/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:59:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/09 17:22:34 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

# define RIGHT			1
# define DOUBLERIGHT	2
# define LEFT			3

# define PERMISSION S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH


typedef struct 	s_env 
{
	char 		*name;
	char 		*value;
}				t_env;

typedef struct	s_redirect
{
	int			type;
	char		*file;
}				t_redirect;

typedef struct 			s_commands {
	char 				**args;
	int					n_args;

	t_redirect			*redirect;
	int 				n_redirect;
}						t_commands;

typedef struct s_all {
	int			n_env;
	t_env		*env;

	int			n_commands;
	t_commands 	*commands;


	int			s_quote;
	int			d_quote;
}				t_all;

t_all	g_all;


/*
** Manage EnvVar functions
*/
void collect_env(char **env);
char *get_env(char *name);
int	set_env(char *name, char *value);

#endif