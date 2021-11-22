/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:39:01 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/22 00:42:26 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"
#include "../../common.h"

char	*collect_env_variables(t_lexer *lexer)
{
	char	*str;
	char	*env_str;
	int		i;
	int		j;

	i = lexer->cur_index;
	while (lexer->cur_char == '_' || ft_isalnum(lexer->cur_char))
		lexer_forward(lexer);
	j = lexer->cur_index;
	env_str = ft_substr(lexer->cmd_line, i, j - i);
	if (env_str == NULL)
		put_error(errno);
	str = get_env(env_str);
	free(env_str);
	if (str == NULL)
		str = ft_strdup(" ");
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
