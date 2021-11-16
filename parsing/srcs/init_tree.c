/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:05:38 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/16 14:09:22 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_tree	*init_tree(t_tree_type type)
{
	t_tree	*tree;

	tree = (t_tree *)malloc(sizeof(t_tree));
	if (tree == NULL)
		put_error(errno);
	tree->type = type;
	tree->pipe_val = (void *)0;
	tree->pipe_size = 0;
	tree->args_val = (void *)0;
	tree->args_size = 0;
	tree->redir = (void *)0;
	tree->redir_size = 0;
	return (tree);
}
