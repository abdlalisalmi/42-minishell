/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:59:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/10/04 11:31:51 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "main.h"

# define RIGHT			1
# define DOUBLERIGHT	2
# define LEFT			3
# define HEREDOC		4

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
}				t_all;

t_all	g_all;


char		*trim_spaces(char *str);
char		*ft_strdup(const char *str);
int			ft_strlen(char *s);

#endif