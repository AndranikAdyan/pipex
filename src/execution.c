/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:09:35 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/13 18:16:24 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(t_data data, int argc, char **argv, char **env)
{
	pid_t	pid;
	int		index;
	int		here_doc;

	here_doc = is_here_doc(argv);
	index = 1 + here_doc;
	while (++index < argc - 1)
	{
		init_data(&data, argv, index);
		pid = fork();
		if (pid == 0)
		{
			set_fds(data, index, argc, here_doc);
			close_fds(data.pipe_fd, data.io_fd, argc, here_doc);
			ft_split_free(data.path);
			if (data.command && data.splited && data.splited[0])
				execve(data.command, data.splited, env);
			perror(data.splited[0]);
			free_data(&data);
			exit(1);
		}
		free_data(&data);
	}
	close_fds(data.pipe_fd, data.io_fd, argc, here_doc);
}
