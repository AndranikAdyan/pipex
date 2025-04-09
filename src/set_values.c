/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:05 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/09 19:44:51 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_fds(int io_fd[2], int **pipe_fd, int index, int argc)
{
	if (index == 2)
	{
		dup2(io_fd[0], STDIN_FILENO);
		dup2(pipe_fd[index - 2][1], STDOUT_FILENO);
	}
	else if (index < argc - 2)
	{
		dup2(pipe_fd[index - 3][0], STDIN_FILENO);
		dup2(pipe_fd[index - 2][1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipe_fd[index - 3][0], STDIN_FILENO);
		dup2(io_fd[1], STDOUT_FILENO);
	}
}

void	set_pipes(int **pipe_fd, int argc)
{
	int	index;

	index = 0;
	while (index < argc - 3)
		pipe(pipe_fd[index++]);
}

int	**malloc_pipe_fd(int ac)
{
	int	**pipe_fd;
	int	i;

	pipe_fd = malloc((ac - 3) * sizeof(int *));
	if (!pipe_fd)
	{
		perror("malloc");
		return (NULL);
	}
	i = 0;
	while (i < ac - 3)
	{
		pipe_fd[i] = malloc(2 * sizeof(int));
		if (!pipe_fd[i])
		{
			perror("malloc");
			while (--i >= 0)
				free(pipe_fd[i]);
			free(pipe_fd);
			return (NULL);
		}
		i++;
	}
	return (pipe_fd);
}

void	free_pipe_fd(int **pipe_fd, int ac)
{
	int	i;

	if (!pipe_fd)
		return ;
	i = 0;
	while (i < ac - 3)
	{
		free(pipe_fd[i]);
		i++;
	}
	free(pipe_fd);
}
