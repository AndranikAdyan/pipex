/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:50:17 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/09 16:26:22 by aadyan           ###   ########.fr       */
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

int		validation(int argc);
char	**get_paths(char **env);
char	*ret_command(char *command, char **path);
void	open_files(int *io_fd, char *filename1, char *filename2);
void	set_fds(int io_fd[2], int pipe_fd[][2], int index, int argc);
void	close_fds(int pipe_fd[][2], int io_fd[2], int argc);

#endif