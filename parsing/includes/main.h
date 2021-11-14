/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:55:39 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/12 01:44:42 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

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

int		ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
char	*ft_itoa(int n);
void	*realloc_edited(void *old_alloc, size_t count, size_t old_size);

#endif