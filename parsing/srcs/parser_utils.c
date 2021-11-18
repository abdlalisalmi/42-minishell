/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:50:45 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/18 23:22:17 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_tree	*fill_pipe_size_of_all_nodes(t_tree *tree)
{
	int		i;

	i = 0;
	if (tree == NULL)
		return (NULL);
	while (i < tree->pipe_size)
	{
		tree->pipe_val[i]->pipe_size = tree->pipe_size;
		i++;
	}
	return (tree);
}

int	update_token(t_parser *parser, t_token_type type)
{
	if (parser->cur_token->type == type)
	{
		free_token(parser->prev_token);
		parser->prev_token = parser->cur_token;
		parser->cur_token = lexer_get_next_token(parser->lexer);
		return (0);
	}
	write(2, "MINISHELL: syntax error near unexpected token `", 48);
	write(2, parser->cur_token->value, ft_strlen(parser->cur_token->value));
	write(2, "'\n", 2);
	return (1);
}

t_tree		*start_parsing(t_parser *parser)
{
	t_tree		*tree_simple_commad;
	t_tree		*pipeline;

	tree_simple_commad = parser_single_command(parser);
	if (tree_simple_commad == NULL)
		return (NULL);
	pipeline = init_tree(TREE_PIPELINE);
	pipeline->pipe_val = (t_tree **)malloc(sizeof(t_tree *));
	if (pipeline->pipe_val == NULL)
		put_error(errno);
	pipeline->pipe_val[0] = tree_simple_commad;
	pipeline->pipe_size += 1;

	if (parser->cur_token->type == TK_PIPE)
	{
		pipeline = parser_pipeline(parser, pipeline);
	}
	return (fill_pipe_size_of_all_nodes(pipeline));
}