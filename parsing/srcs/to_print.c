/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:26:13 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/14 15:00:54 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	print_redirection(t_redirect *node)
{
	printf("REDIRECTION(%s, %d)\n", node->filename, node->type);
}

void	print_command(t_tree *node)
{
	int		i;

	i = 0;
	while (i < node->redir_size)
	{
		print_redirection(node->redir[i]);
		i++;
	}

	i = 0;
	printf("ARG SIZE === %d\n", node->args_size);
	while (i < node->args_size)
	{
		printf("ARG %d === (%s)\n", i, node->args_val[i]);
		i++;
	}
}

void	print_pipelines(t_tree *node)
{
	int		i;

	i = 0;
	while (i < node->pipe_size)
	{
		print_command(node->pipe_val[i]);
		i++;
	}
}

int		to_print(t_tree *node)
{
	if (node != NULL)
		print_pipelines(node);
	return (0);
}