/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:04:25 by aes-salm          #+#    #+#             */
/*   Updated: 2021/11/09 17:40:35 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../execution.h"

char	*get_cmd_path(char *cmd)
{
	char **paths;
	char *full_path;
	char *command;
	int i;
	int fd;
	
	paths = ft__split(get_env("PATH"), ':');
	i = -1;
	while (paths[++i])
	{
		command = ft_strappend("/", cmd);
		full_path = ft_strappend(paths[i], command);
		fd = open(full_path, O_RDONLY);
		if (fd > -1)
		{
			close(fd);
			free(command);
			free_d_pointer(paths);
			return (full_path);
		}
		free(command);
		free(full_path);
	}
	free_d_pointer(paths);
	return (NULL);
}
