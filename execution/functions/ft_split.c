/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:30:51 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/19 16:56:51 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

static int	get_words(char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	get_chars(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**fill_out(char *s, char **out, char c)
{
	int		i;
	int		x;
	int		xx;

	i = 0;
	x = 0;
	xx = 0;
	while (s[i] && x < get_words(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
			out[x] = malloc(sizeof(char) * get_chars(&s[i], c) + 1);
		while (s[i] != c && s[i])
			out[x][xx++] = s[i++];
		out[x++][xx] = '\0';
		xx = 0;
	}
	out[x] = NULL;
	return (out);
}

char	**ft__split(const char *ss, char c)
{
	char	**out;
	char	*s;

	s = (char *)ss;
	if (!s || *s == '\0')
	{
		out = malloc(sizeof(char *));
		*out = NULL;
	}
	else
	{
		out = malloc((get_words(s, c) + 1) * sizeof(char *));
		out = fill_out(s, out, c);
	}
	return (out);
}
