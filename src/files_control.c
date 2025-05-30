/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:44:41 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/17 18:37:08 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_files(int *io_fd, char *filename1, char *filename2, int here_doc)
{
	if (here_doc)
		io_fd[1] = open(filename2, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else
		io_fd[1] = open(filename2, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (io_fd[1] == -1)
	{
		perror(filename2);
		return (0);
	}
	if (here_doc)
	{
		filename1 = FILE_NAME;
		io_fd[0] = open(filename1, O_RDONLY, 0644);
	}
	else
		io_fd[0] = open(filename1, O_RDONLY);
	if (io_fd[0] == -1)
	{
		perror(filename1);
		return (0);
	}
	return (1);
}

void	close_fds(int **pipe_fd, int io_fd[2], int argc, int here_doc)
{
	int	index;

	index = 0;
	while (index < argc - 4 - here_doc)
	{
		close(pipe_fd[index][0]);
		close(pipe_fd[index][1]);
		free(pipe_fd[index]);
		++index;
	}
	free(pipe_fd);
	unlink(FILE_NAME);
	if (io_fd[0] != -1)
		close(io_fd[0]);
	if (io_fd[1] != -1)
		close(io_fd[1]);
}
