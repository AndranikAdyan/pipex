/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:46:05 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/09 16:12:59 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_fds(int io_fd[2], int pipe_fd[][2], int index, int argc)
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
