/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_single_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:02:44 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/14 19:41:39 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_red_type	get_redirections_type(t_parser *parser)
{
	t_red_type	type;

	if (parser->cur_token->type == TK_GREAT)
		type = OUTPUT;
	else if (parser->cur_token->type == TK_DGREAT)
		type = APPEND;
	else if (parser->cur_token->type == TK_LESS)
		type = INPUT;
	else
		type = HERE_DOC;
	return (type);
}

int		parse_redirections(t_parser *parser, t_tree *tree)
{
	t_red_type 	type;

	type = get_redirections_type(parser);
	update_token(parser, parser->cur_token->type);
	if (update_token(parser, TK_WORD))
		return (1);
	tree->redir = realloc_edited(tree->redir, sizeof(t_redirect *), tree->redir_size);
	tree->redir_size += 1;
	tree->redir[tree->redir_size - 1] = (t_redirect *)malloc(sizeof(t_redirect));
	if (tree->redir[tree->redir_size - 1] == NULL)
		put_error(errno);
	tree->redir[tree->redir_size - 1]->type = type;
	tree->redir[tree->redir_size - 1]->filename = parser->prev_token->value;
	return (0);
}


void	parse_cmd_args(t_parser *parser, t_tree *tree)
{
	while (parser->cur_token->type == TK_WORD)
	{
		tree->args_val = realloc_edited(tree->args_val, sizeof(char *), tree->args_size);
		if (tree->args_val == NULL)
			put_error(errno);
		tree->args_size += 1;
		tree->args_val[tree->args_size - 1] = parser->cur_token->value;
		update_token(parser, TK_WORD);
	}
	// to_print(tree);
	// printf("N_COMMANDS+++ === %d\n", tree->pipe_size);
}

t_tree		*parser_single_command(t_parser *parser)
{
	t_tree *tree;
	// check errors here
	if (parser_check_errors(parser))
		return (NULL);
	tree = init_tree(TREE_COMMAND);
	while (parser->cur_token->type != TK_PIPE
		&& parser->cur_token->type != TK_EOF)
	{
		if (parser->cur_token->type == TK_WORD)
			parse_cmd_args(parser, tree);
		else if (parse_redirections(parser, tree))
			return (free_tree_command(tree));
	}
	tree->args_val = realloc_edited(tree->args_val, sizeof(char *), tree->args_size);
	if (tree->args_val == NULL)
		put_error(errno);
	tree->args_val[tree->args_size] = NULL;
	return (tree);
}