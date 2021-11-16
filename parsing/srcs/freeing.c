/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:37:21 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/16 14:09:03 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	free_token(t_token *token)
{
	if (token != NULL)
	{
		if (token->type != TK_WORD)
			free(token->value);
		free(token);
	}
}

void	free_parser(t_parser *parser)
{
	if (parser != NULL)
	{
		if (parser->lexer != NULL)
		{
			free(parser->lexer->cmd_line);
			free(parser->lexer);
		}
		free_token(parser->cur_token);
		free_token(parser->prev_token);
		free(parser);
	}
}

t_tree	*free_tree_command(t_tree *tree)
{
	if (tree != NULL)
	{
		while (tree->args_size-- > 0)
			free(tree->args_val[tree->args_size]);
		free(tree->args_val);
		while (tree->redir_size-- > 0)
		{
			free(tree->redir[tree->redir_size]->filename);
			free(tree->redir[tree->redir_size]);
		}
		free(tree->redir);
		free(tree);
	}
	return (NULL);
}

t_tree	*free_tree_pipeline(t_tree *tree)
{
	if (tree != NULL)
	{
		while (tree->pipe_size-- > 0)
			free_tree_command(tree->pipe_val[tree->pipe_size]);
		free(tree->pipe_val);
		free(tree);
	}
	return (NULL);
}
