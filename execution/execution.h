#ifndef EXECUTION_H
# define EXECUTION_H

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


/*
** Builtins commands
*/
char	*ft_pwd(void);
int		ft_cd(char **args, int n_args);
int		ft_export(char **args, int n_args);
void	ft_unset(char **args, int n_args);
void	ft_env(char **args, int n_args);
void	ft_exit(char **args, int n_args);
void 	ft_echo(char **args, int n_args);

/*
** Manage EnvVar functions
*/
void collect_env(char **env);
char *get_env(char *name);
int	set_env(char *name, char *value);

/*
** Manage Execution functions
*/
void	execute_single_command(t_commands command, char **envp);


/*
** Utils functions
*/
void	free_d_pointer(char **ptr);
char	*get_cmd_path(char *cmd);

/*
** Help functions
*/
int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_isdigit(int arg);
char	*ft_strappend(char *s1, char *s2);
char	**ft_split(const char *ss, char c);


#endif