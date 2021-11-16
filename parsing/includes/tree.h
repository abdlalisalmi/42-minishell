/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:58:16 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/16 13:38:24 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "./main.h"

typedef enum e_red_type
{
	INPUT,
	OUTPUT,
	APPEND,
	HERE_DOC,
}				t_red_type;

typedef struct s_redirect
{
	t_red_type	type;
	char		*filename;
}				t_redirect;

typedef enum e_tree_type
{
	TREE_PIPELINE,
	TREE_COMMAND,
}				t_tree_type;

typedef struct s_tree
{
	t_tree_type		type;
	struct s_tree	**pipe_val;
	int				pipe_size;
	char			**args_val;
	int				args_size;
	t_redirect		**redir;
	int				redir_size;
}				t_tree;

int	check_cmd_line(char **line);

#endif
