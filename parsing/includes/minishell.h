/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:59:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/10/05 12:29:48 by atahiri          ###   ########.fr       */
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


char		*trim_spaces(char *str);
char		*ft_strdup(const char *str);
int			ft_strlen(char *s);
int			ft_strcmp(char *str1, char *str2);
void		ft_putstr_fd(char *s, int fd);
int			verif_quotes(char *line);
char		**ft_split(const char *ss, char c);

int			starts_with(char *line);
int			check_semicolon(char *line);
int			ft_dplen(char **ptr);
void		print_out(char **to_print);

#endif