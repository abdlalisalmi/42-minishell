/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:59:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/09 16:57:45 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../common.h"
# include "main.h"


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