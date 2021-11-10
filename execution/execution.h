#ifndef EXECUTION_H
# define EXECUTION_H

# include "../common.h"


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
** Manage Execution functions
*/
// void	start_execution(void);
void	execute_single_command(t_commands command);

/*
** Utils functions
*/
void	free_d_pointer(char **ptr);
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


#endif