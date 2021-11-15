/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_others.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:39:41 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/15 01:38:41 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

int	check_closed_quotes(char *str, int index, char c)
{
	int		i;

	i = index;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*collect_single_quotes(t_lexer *lexer)
{
	char	*str;
	int		i;
	int		j;

	lexer_forward(lexer);
	if (!check_closed_quotes(lexer->cmd_line, lexer->cur_index, '\''))
		return (ft_strdup("'"));
	i = lexer->cur_index;
	while (lexer->cur_char != '\'')
		lexer_forward(lexer);
	j = lexer->cur_index;
	lexer_forward(lexer);
	str = ft_substr(lexer->cmd_line, i, j - i);
	if (str == NULL)
		put_error(errno);
	return (str);
}

char		*collect_simple_chars(t_lexer *lexer)
{
	char	*str;
	int		i;
	int		j;

	i = lexer->cur_index;
	while (!special_characters(lexer->cur_char) && lexer->cur_char != '"'
		&& lexer->cur_char != '\'' && lexer->cur_char != '$')
		lexer_forward(lexer);
	j = lexer->cur_index;
	str = ft_substr(lexer->cmd_line, i, j - i);
	if (str == NULL)
		put_error(errno);
	return (str);
}


void	add_to_value(char **value, char *str)
{
	char	*fr;

	fr = *value;
	*value = ft_strjoin(*value, str);
	if (*value == NULL)
		put_error(errno);
	free(fr);
	free(str);
}

t_token		*collect_others(t_lexer *lexer)
{
	// need tp handle env variabls
	char	*value;
	char	*str;

	value = ft_strdup("");
	while (!special_characters(lexer->cur_char))
	{
		if (lexer->cur_char == '\'')
			str = collect_single_quotes(lexer);
		else if (lexer->cur_char == '"')
			str = collect_double_quotes(lexer);
		else if (lexer->cur_char == '$')
			str = collect_env_inline(lexer, ft_strlen(value));
		else
			str = collect_simple_chars(lexer);
		add_to_value(&value, str);
	}
	return (init_token(TK_WORD, value));
}