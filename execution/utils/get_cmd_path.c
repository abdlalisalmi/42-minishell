/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:04:25 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/19 11:42:42 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

char	*search_for_path(char *cmd, char *path)
{
	char	*full_path;
	char	*command;
	int		fd;

	command = ft_strappend("/", cmd);
	full_path = ft_strappend(path, command);
	fd = open(full_path, O_RDONLY);
	free(command);
	if (fd > -1)
	{
		close(fd);
		return (full_path);
	}
	free(full_path);
	return (NULL);
}

char	*get_cmd_path(char *cmd)
{
	char	**paths;
	char	*full_path;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	paths = ft__split(get_env("PATH"), ':');
	i = -1;
	while (paths[++i])
	{
		full_path = search_for_path(cmd, paths[i]);
		if (full_path != NULL)
		{
			free_d_pointer(paths);
			return (full_path);
		}
	}
	free_d_pointer(paths);
	return (NULL);
}
