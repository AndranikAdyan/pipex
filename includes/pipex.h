/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:50:17 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/11 11:44:08 by aadyan           ###   ########.fr       */
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

# define FILE_NAME "/tmp/here_doc.tmp"

typedef struct s_data
{
	char	*command;
	char	**splited;
	char	**path;
	int		io_fd[2];
	int		**pipe_fd;
}	t_data;

int		validation(int argc, char **argv);
char	**get_paths(char **env);
void	execute_cmd(t_data data, int argc, char **argv, char**env);
char	*ret_command(char *command, char **path);
void	open_files(int *io_fd, char *filename1, char *filename2, int here_doc);
void	set_fds(t_data data, int index, int argc, int here_doc);
void	close_fds(int **pipe_fd, int io_fd[2], int argc);
void	set_pipes(int **pipe_fd, int argc, int here_doc);

void	init_data(t_data *data, char **argv, int index);
void	free_data(t_data *data);

int		**malloc_pipe_fd(int ac);
void	free_pipe_fd(int **pipe_fd, int ac);

int		is_here_doc(char **argv);
void	here_doc_input(t_data data, char **argv);

#endif