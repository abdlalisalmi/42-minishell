/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:14:03 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/11 11:15:05 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_parser *init_parser_lexer(char *line)
{
	t_parser *parser;
	t_lexer *lexer;

	lexer = init_lexer(line);
	parser = (t_parser *)malloc(sizeof(t_parser));
	if (parser == NULL)
		put_error(errno);
	parser->lexer = lexer;
	parser->cur_token = lexer_get_next_token(lexer);
	parser->prev_token = NULL;
	return (parser);
}