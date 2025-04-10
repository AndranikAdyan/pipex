/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:09:35 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/11 10:53:53 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(t_data data, int argc, char **argv, char **env)
{
	pid_t	pid;
	int		index;

	index = 1;
	while (++index < argc - 1)
	{
		init_data(&data, argv, index);
		pid = fork();
		if (pid == 0)
		{
			set_fds(data, index, argc);
			close_fds(data.pipe_fd, data.io_fd, argc);
			ft_split_free(data.path);
			execve(data.command, data.splited, env);
			perror(data.splited[0]);
			exit(errno);
		}
		free_data(&data);
	}
	close_fds(data.pipe_fd, data.io_fd, argc);
}
