/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:58:19 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/16 13:34:03 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

typedef enum e_token_type
{
	TK_WORD,
	TK_PIPE,
	TK_GREAT,
	TK_DGREAT,
	TK_LESS,
	TK_HERE_DOC,
	TK_EOF
}			t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}			t_token;

void		put_error(int errnum);
t_token		*init_token(t_token_type type, char *value);

#endif