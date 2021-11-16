/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_double_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:32:03 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/16 14:02:09 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void	collect_simple_chars_in_double_q(t_lexer *lexer, char **value)
{
	char	*str;
	char	*fr;
	int		index_i;
	int		index_f;

	index_i = lexer->cur_index;
	while (lexer->cur_char != '"' && lexer->cur_char != '\0'
		&& lexer->cur_char != '$')
		lexer_forward(lexer);
	index_f = lexer->cur_index;
	if (lexer->cur_char == '\0')
		return ;
	str = ft_substr(lexer->cmd_line, index_i, index_f - index_i);
	if (str == NULL)
		put_error(errno);
	fr = *value;
	*value = ft_strjoin(*value, str);
	if (*value == NULL)
		put_error(errno);
	free(str);
	free(fr);
}

char	*collect_double_quotes(t_lexer *lexer)
{
	char	*value;

	lexer_forward(lexer);
	if (!check_closed_quotes(lexer->cmd_line, lexer->cur_index, '"'))
		return (ft_strdup("\""));
	value = ft_strdup("");
	while (lexer->cur_char != '"')
	{
		if (lexer->cur_char == '$')
			lexer_collect_env_variables(lexer, &value);
		else
			collect_simple_chars_in_double_q(lexer, &value);
	}
	lexer_forward(lexer);
	return (value);
}
