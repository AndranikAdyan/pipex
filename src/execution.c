/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:09:35 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/09 20:16:38 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(t_data data, int argc, char **argv, char**env)
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
			set_fds(data.io_fd, data.pipe_fd, index, argc);
			close_fds(data.pipe_fd, data.io_fd, argc);
			execve(data.command, data.splited, env);
			perror(data.splited[0]);
			exit(errno);
		}
		free_data(&data);
	}
	while (wait(NULL) != -1)
		;
}
