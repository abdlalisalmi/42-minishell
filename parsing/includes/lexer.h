/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:58:25 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/16 13:31:57 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "tokenizer.h"
# include "main.h"

typedef struct s_lexer
{
	char	*cmd_line;
	int		cur_index;
	char	cur_char;
}			t_lexer;

t_token		*lexer_get_next_token(t_lexer *lexer);
t_lexer		*init_lexer(char *cmd_line);
void		lexer_forward(t_lexer *lexer);
void		lexer_skip_whitespaces(t_lexer *lexer);
int			special_characters(int c);
t_token		*collect_others(t_lexer *lexer);
int			special_characters(int c);
char		*collect_double_quotes(t_lexer *lexer);
int			check_closed_quotes(char *str, int index, char c);
void		lexer_collect_env_variables(t_lexer *lexer, char **value);
char		*collect_env_inline(t_lexer *lexer, size_t size);

#endif