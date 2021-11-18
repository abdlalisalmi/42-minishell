/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:27:05 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/18 23:21:57 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

t_token	*adva_return(t_lexer *lexer, t_token *token)
{
	lexer_forward(lexer);
	return (token);
}

t_token	*lexer_collect_great_redirection(t_lexer *lexer)
{
	lexer_forward(lexer);
	if (lexer->cur_char == '>')
		return (adva_return(lexer, init_token(TK_DGREAT, ft_strdup(">>"))));
	return (init_token(TK_GREAT, ft_strdup(">")));
}

t_token	*lexer_collect_less_redirection(t_lexer *lexer)
{
	lexer_forward(lexer);
	if (lexer->cur_char == '<')
		return (adva_return(lexer, init_token(TK_HERE_DOC, ft_strdup("<<"))));
	return (init_token(TK_LESS, ft_strdup("<")));
}

t_token	*lexer_get_next_token(t_lexer *lexer)
{
	while (lexer->cur_char != '\0')
	{
		lexer_skip_whitespaces(lexer);
		if (lexer->cur_char == '|')
			return (adva_return(lexer, init_token(TK_PIPE, ft_strdup("|"))));
		if (lexer->cur_char == '>')
			return (lexer_collect_great_redirection(lexer));
		if (lexer->cur_char == '<')
			return (lexer_collect_less_redirection(lexer));
		if (lexer->cur_char != '\0')
			return (collect_others(lexer));
	}
	return (init_token(TK_EOF, ft_strdup("newline")));
}
