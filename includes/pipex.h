/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:50:17 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/09 20:16:57 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "libft.h"

typedef struct s_data
{
	char	*command;
	char	**splited;
	char	**path;
	int		io_fd[2];
	int		**pipe_fd;
}	t_data;


int		validation(int argc);
char	**get_paths(char **env);
void	execute_cmd(t_data data, int argc, char **argv, char**env);
char	*ret_command(char *command, char **path);
void	open_files(int *io_fd, char *filename1, char *filename2);
void	set_fds(int io_fd[2], int **pipe_fd, int index, int argc);
void	close_fds(int **pipe_fd, int io_fd[2], int argc);
void	set_pipes(int **pipe_fd, int argc);

void	init_data(t_data *data, char **argv, int index);
void	free_data(t_data *data);

int		**malloc_pipe_fd(int ac);
void	free_pipe_fd(int **pipe_fd, int ac);

#endif