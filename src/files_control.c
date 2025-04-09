/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:44:41 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/09 16:13:30 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(int *io_fd, char *filename1, char *filename2)
{
	io_fd[1] = open(filename2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (io_fd[1] == -1)
	{
		perror(filename2);
		exit(errno);
	}
	io_fd[0] = open(filename1, O_RDONLY);
	if (io_fd[0] == -1)
	{
		close(io_fd[1]);
		perror(filename1);
		exit(errno);
	}
}

void	close_fds(int pipe_fd[][2], int io_fd[2], int argc)
{
	int	index;

	index = 0;
	while (index < argc - 3)
	{
		close(pipe_fd[index][0]);
		close(pipe_fd[index][1]);
		++index;
	}
	close(io_fd[0]);
	close(io_fd[1]);
}
