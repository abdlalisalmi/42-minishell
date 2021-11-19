/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_execute_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:40:36 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/19 11:59:46 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tree.h"
#include "../../common.h"

void	fill_redirections(t_redirect *node, int cmd_index, int redire_index)
{
	g_all.commands[cmd_index].redirect[redire_index].type = node->type;
	g_all.commands[cmd_index].redirect[redire_index].file = node->filename;
}

void	fill_command(t_tree *node, int cmd_index)
{
	int		i;

	i = -1;
	g_all.commands[cmd_index].n_redirect = node->redir_size;
	g_all.commands[cmd_index].redirect = malloc(sizeof(t_redirections)
			* node->redir_size);
	while (++i < node->redir_size)
		fill_redirections(node->redir[i], cmd_index, i);
	i = -1;
	g_all.commands[cmd_index].n_args = node->args_size;
	g_all.commands[cmd_index].args = malloc(sizeof(char *)
			* (node->args_size + 1));
	while (++i < node->args_size)
		g_all.commands[cmd_index].args[i] = node->args_val[i];
	g_all.commands[cmd_index].args[i] = NULL;
}

void	fill_pipelines(t_tree *node)
{
	int		i;

	i = -1;
	g_all.n_commands = node->pipe_size;
	g_all.commands = malloc(sizeof(t_commands) * g_all.n_commands);
	while (++i < g_all.n_commands)
		fill_command(node->pipe_val[i], i);
}

int	fill_execute_struct(t_tree *node)
{
	if (node != NULL)
		fill_pipelines(node);
	return (0);
}
