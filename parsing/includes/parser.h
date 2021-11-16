/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:58:22 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/16 13:33:18 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tree.h"
# include "lexer.h"
# include "../../common.h"

typedef struct s_parser
{
	t_lexer	*lexer;
	t_token	*cur_token;
	t_token	*prev_token;
}			t_parser;

t_parser	*init_parser_lexer(char *line);
t_tree		*init_tree(t_tree_type type);
t_tree		*start_parsing(t_parser *parser);
t_tree		*parser_single_command(t_parser *parser);
void		free_token(t_token *token);
int			update_token(t_parser *parser, t_token_type type);
int			parser_check_errors(t_parser *parser);
t_tree		*free_tree_command(t_tree *tree);
t_tree		*free_tree_pipeline(t_tree *tree);
void		free_parser(t_parser *parser);
t_tree		*parser_pipeline(t_parser *parser, t_tree *tree);
void		fill_execute_struct(t_tree *tree);
// int		to_print(t_tree *node);
#endif