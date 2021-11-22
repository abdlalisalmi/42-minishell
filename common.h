/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:59:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/22 12:42:00 by aes-salm         ###   ########.fr       */
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

typedef struct s_env
{
	char		*name;
	char		*value;
}				t_env;

typedef struct s_redirections
{
	int			type;
	char		*file;
}				t_redirections;

typedef struct s_commands {
	char				**args;
	int					n_args;
	t_redirections		*redirect;
	int					n_redirect;
	int					fd[2];
}				t_commands;

typedef struct s_all {
	int			n_env;
	t_env		*env;
	int			exit_code;
	int			n_commands;
	t_commands	*commands;
	int			heredoc;
	int			is_child;
}				t_all;

t_all	g_all;

/*
** Manage EnvVar functions
*/
void	collect_env(char **env);
char	*get_env(char *name);
void	sort_env(void);
int		set_env(char *name, char *value);

/*
** Execution endpoint
*/
void	free_d_pointer(char **ptr);
void	start_execution(void);

#endif