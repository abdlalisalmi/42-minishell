/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:39:01 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/17 16:08:32 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"
#include "../../common.h"

char	*collect_env_variables(t_lexer *lexer)
{
	char	*fr;
	char	*str;
	int		i;
	int		j;

	i = lexer->cur_index;
	while (lexer->cur_char == '_' || ft_isalnum(lexer->cur_char))
		lexer_forward(lexer);
	j = lexer->cur_index;
	str = ft_substr(lexer->cmd_line, i, j - i);
	if (str == NULL)
		put_error(errno);
	fr = str;
	str = get_env(str);
	if (str == NULL)
		str = ft_strdup(" ");
	else
		str = ft_strdup(str);
	free(fr);
	return (str);
}

void	lexer_collect_env_variables(t_lexer *lexer, char **value)
{
	char	*str;
	char	*fr;

	lexer_forward(lexer);
	if (lexer->cur_char == '?')
	{
		lexer_forward(lexer);
		str = get_env("?");
	}
	else if (lexer->cur_char != '_' && !ft_isalpha(lexer->cur_char))
	{
		str = ft_substr(lexer->cmd_line, lexer->cur_index - 1, 2);
		if (str == NULL)
			put_error(errno);
		lexer_forward(lexer);
	}
	else
		str = collect_env_variables(lexer);
	fr = *value;
	*value = ft_strjoin(*value, str);
	if (*value == NULL)
		put_error(errno);
	free(str);
	free(fr);
}
