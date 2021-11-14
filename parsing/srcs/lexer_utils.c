/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:41:10 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/11 15:41:43 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

t_lexer	*init_lexer(char *cmd_line)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (lexer == NULL)
		put_error(errno);
	lexer->cmd_line = cmd_line;
	lexer->cur_index = 0;
	lexer->cur_char = cmd_line[0];
	lexer->exit_status = 0; // need to handle in future
	return (lexer);
}

void	lexer_forward(t_lexer *lexer)
{
	if (lexer->cur_char != '\0')
	{
		lexer->cur_index += 1;
		lexer->cur_char = lexer->cmd_line[lexer->cur_index];
	}
}

void	lexer_skip_whitespaces(t_lexer *lexer)
{
	while (lexer->cur_char == ' ' || lexer->cur_char == '\t')
		lexer_forward(lexer);
}

int	special_characters(int c)
{
	if (c == '|' || c == '>' || c == '<' || c == '\0'
		|| c == ' ' || c == '\t')
		return (1);
	return (0);
}
