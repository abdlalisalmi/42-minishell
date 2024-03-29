/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:07:05 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/22 12:41:52 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../common.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>

# define LEFT			0
# define RIGHT			1
# define DOUBLERIGHT	2
# define HEREDOC		3
# define NONE			4

# define FILE_D_IN 0
# define FILE_D_OUT 1
# define PIPE_IN 1
# define PIPE_OUT 0

# define TRUE 1
# define FALSE 0

/*
** Builtins commands
*/
char	*ft_pwd(void);
int		ft_cd(char **args, int n_args);
int		ft_export(char **args, int n_args);
void	ft_unset(char **args, int n_args);
void	ft_env(char **args, int n_args);
void	ft_exit(char **args, int n_args);
void	ft_echo(char **args, int n_args);

/*
** Manage Execution functions
*/
void	init_pipes(int index);
void	close_pipes(int index);
int		setup_redirections(t_commands command);
void	setup_heredoc(void);
void	remove_heredoc_files(void);
void	save_std_fds(int *stdin, int *stdout);
void	restore_std_fds(int type, int stdin, int stdout);
int		is_builtins(char *cmd);
void	exec_builtins(char **args, int n_args);
void	execute_single_command(t_commands command);
void	execute_multiple_commands(void);
void	handle_errors(char *arg, int _errno);

/*
** Utils functions
*/
char	*get_cmd_path(char *cmd);
char	**to_envp(void);

/*
** Help functions
*/
int		ft__strlen(char *s);
void	ft__putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft__strcmp(char *str1, char *str2);
char	*ft__strdup(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_isdigit(int arg);
char	*ft_strappend(char *s1, char *s2);
char	**ft__split(const char *ss, char c);
char	*ft__itoa(int n);
char	*ft__substr(char const *s, unsigned int start, size_t len);
int		ft_strcompare(char *str1, char *str2);
char	*ft__strjoin(char *s1, char *s2);

#endif
