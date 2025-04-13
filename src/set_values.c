/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:05 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/13 18:29:42 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_fds(t_data data, int index, int argc, int here_doc)
{
	if (index == 2 + here_doc)
	{
		dup2(data.io_fd[0], STDIN_FILENO);
		dup2(data.pipe_fd[index - 2 - here_doc][1], STDOUT_FILENO);
	}
	else if (index < argc - 2)
	{
		dup2(data.pipe_fd[index - 3 - here_doc][0], STDIN_FILENO);
		dup2(data.pipe_fd[index - 2 - here_doc][1], STDOUT_FILENO);
	}
	else
	{
		dup2(data.pipe_fd[index - 3 - here_doc][0], STDIN_FILENO);
		dup2(data.io_fd[1], STDOUT_FILENO);
	}
}

void	set_pipes(int **pipe_fd, int argc, int here_doc)
{
	int	index;

	index = 0;
	while (index < argc - 4 - here_doc)
	{
		if (pipe(pipe_fd[index]) == -1)
		{
			while (--index >= 0)
			{
				close(pipe_fd[index][0]);
				close(pipe_fd[index][1]);
				free(pipe_fd[index]);
			}
			free(pipe_fd);
			perror("pipe failed");
			exit(1);
		}
		index++;
	}
}

int	**malloc_pipe_fd(int ac, int here_doc)
{
	int	**pipe_fd;
	int	i;

	pipe_fd = malloc((ac - 4 - here_doc) * sizeof(int *));
	if (!pipe_fd)
	{
		perror("malloc");
		return (NULL);
	}
	i = 0;
	while (i < ac - 4 - here_doc)
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
