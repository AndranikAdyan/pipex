/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:56:10 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/11 11:16:12 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ret_command(char *command, char **path)
{
	char	*command_path;
	int		i;

	i = 0;
	if (!path)
		return (ft_strdup(command));
	while (path[i])
	{
		command_path = ft_strjoin(path[i], command, '/');
		if (access(command_path, F_OK) == 0)
			return (command_path);
		free(command_path);
		i++;
	}
	return (NULL);
}

int	validation(int argc, char **argv)
{
	if (argc < 5 || (argc < 6 && is_here_doc(argv)))
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 1);
		return (0);
	}
	return (1);
}
