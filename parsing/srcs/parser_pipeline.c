/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:58:27 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/14 19:12:20 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_tree		*parser_pipeline(t_parser *parser, t_tree *tree)
{
	t_tree	*simple_cmd;

	while (parser->cur_token->type == TK_PIPE)
	{
		update_token(parser, TK_PIPE);
		simple_cmd = parser_single_command(parser);
		if (simple_cmd == NULL)
			return (free_tree_pipeline(tree));
		tree->pipe_val = realloc_edited(tree->pipe_val, sizeof(t_tree *), tree->pipe_size);
		tree->pipe_size += 1;
		tree->pipe_val[tree->pipe_size - 1] = simple_cmd;
	}
	
	// to_print(tree);
	return (tree);
}