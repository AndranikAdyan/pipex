/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:56:10 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/08 19:26:45 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ret_command(char **env, char *command)
{
	char	**paths;
	char	*command_path;
	int		i;

	paths = get_paths(env);
	i = 0;
	while (paths[i])
	{
		command_path = ft_strjoin(paths[i], command, '/');
		if (access(command_path, F_OK) == 0)
		{
			ft_strjoin_free(paths);
			return (command_path);
		}
		free(command_path);
		i++;
	}
	ft_strjoin_free(paths);
	return (NULL);
}

int		validation(int argc, char **argv)
{
	if (argc < 4)
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 2);
		return (0);
	}
	return (1);
	(void)argv;
}