/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:11:35 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/18 23:39:31 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	parser_check_errors(t_parser *parser)
{
	if (parser->cur_token->type == TK_PIPE
		|| parser->cur_token->type == TK_EOF)
		return (update_token(parser, TK_WORD));
	return (0);
}
