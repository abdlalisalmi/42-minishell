/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_env_inline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:32:28 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/15 01:48:43 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexer.h"

void	check_allocation(char *str)
{
	if (str == NULL)
		put_error(errno);
}

char	*get_next_word(char *env, int *index)
{
	char	*word;
	int		index_i;
	int		index_f;

	while (env[*index] == ' ' || env[*index] == '\t')
		*index += 1;
	index_i = *index;
	while (env[*index] != ' ' && env[*index] != '\t' && env[*index] != '\0')
		*index += 1;
	index_f = *index;
	word = ft_substr(env, index_i, index_f - index_i);
	if (word == NULL)
		put_error(errno);
	return (word);
}

char	*split_words(t_lexer *lexer, char *env, char *str, size_t n)
{
	char	*word;
	char	*fr;
	int		i;

	i = 0;
	while (n-- > 0)
	{
		word = get_next_word(env, &i);
		fr = str;
		if (n > 0 || ((env[i] == ' ' || env[i] == '\t')
				&& !special_characters(lexer->cur_char)))
		{
			str = ft_strjoin_char(str, word, ' ');
			check_allocation(str);
		}
		else
		{
			str = ft_strjoin(str, word);
			check_allocation(str);
		}
		free(fr);
		free(word);
	}
	free(env);
	return (str);
}

char	*collect_env_inline(t_lexer *lexer, size_t size)
{
	char	*env;
	char	*str;
	size_t	num_of_words;

	env = ft_strdup("");
	lexer_collect_env_variables(lexer, &env);
	str = ft_strdup("");
	num_of_words = ft_num_words(env);
	if (num_of_words == 0)
	{
		if ((env[0] == ' ' || env[0] == '\t') && size > 0
			&& !special_characters(lexer->cur_char))
		{
			free(str);
			str = ft_strdup(" ");
		}
		free(env);
		return (str);
	}
	if ((env[0] == ' ' || env[0] == '\t') && size > 0)
	{
		free(str);
		str = ft_strdup(" ");
	}
	return (split_words(lexer, env, str, num_of_words));
}