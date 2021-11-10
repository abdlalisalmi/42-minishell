/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:05:22 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/10 12:08:58 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void verif_backslash_squote(char *line, int i)
{
	int backslash;

	backslash = 0;
	while (i >= 0 && line[i] == '\\')
	{
		backslash++;
		i--;
	}
	backslash = backslash % 2;
	if (backslash == 0 && g_all.s_quote == 0)
	{
		g_all.s_quote = 1;
		return;
	}
	if (backslash == 0 && g_all.s_quote == 1)
	{
		g_all.s_quote = 0;
		return;
	}
}

void verif_backslash_dquote(char *line, int i)
{
	int backslash;

	backslash = 0;
	while (i >= 0 && line[i] == '\\')
	{
		backslash++;
		i--;
	}
	backslash = backslash % 2;
	if (backslash == 0 && g_all.d_quote == 0)
	{
		g_all.d_quote = 1;
		return;
	}
	if (backslash == 0 && g_all.d_quote == 1)
	{
		g_all.d_quote = 0;
		return;
	}
}

int check_semicolon(char *line)
{
	if (line[0] == ';')
	{
		ft_putstr_fd("syntax error near unexpected token `;'\n", 1);
		return (1);
	}
	return 0;
}

int starts_with(char *line)
{
	if (*line == '|')
	{
		ft_putstr_fd("syntax error near unexpected token `|'\n", 1);
		return (1);
	}
	else if (*line == '\\' && *(line + 1) != '\\')
		ft_putstr_fd(">\n", 1);
	return (0);
}

int verif_quotes(char *line)
{
	int i;

	i = -1;
	g_all.d_quote = 0;
	g_all.s_quote = 0;
	while (line[++i])
	{
		if ((line[i] == '\"' && g_all.d_quote == 0 && i == 0) || (line[i] ==
			'\"' && g_all.d_quote == 0 && line[i - 1] != '\\' && g_all.s_quote == 0))
			g_all.d_quote = 1;
		else if (line[i] == '\"' && g_all.d_quote == 1 && line[i - 1] != '\\')
			g_all.d_quote = 0;
		if ((line[i] == '\'' && g_all.s_quote == 0 && i == 0) || (line[i] ==
			'\'' && g_all.s_quote == 0 && line[i - 1] != '\\' && g_all.d_quote == 0))
			g_all.s_quote = 1;
		else if (line[i] == '\'' && g_all.s_quote == 1 && line[i - 1] != '\\')
			g_all.s_quote = 0;
		// if (i != 0 && line[i] == '\'' && line[i - 1] == '\\')
		// 	verif_backslash_squote(line, i - 1);
		// if (i != 0 && line[i] == '\"' && line[i - 1] == '\\')
		// 	verif_backslash_dquote(line, i - 1);
	}
	if (g_all.s_quote == 1 || g_all.d_quote == 1)
		return (-1);
	return (0);
}