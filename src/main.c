/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:48:45 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/09 16:35:12 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	char	*command;
	int		io_fd[2];
	int		pipe_fd[argc - 3][2];
	char	**splited;
	int		index;
	pid_t	pid;
	char	**path;

	if (!validation(argc))
		return (1);
	index = 0;
	while (index < argc - 3)
		pipe(pipe_fd[index++]);
	index = 2;
	path = get_paths(env);
	open_files(io_fd, argv[1], argv[argc - 1]);
	while (index < argc - 1)
	{
		splited = ft_split(argv[index], ' ');
		command = ret_command(splited[0], path);
		pid = fork();
		if (pid == 0)
		{
			set_fds(io_fd, pipe_fd, index, argc);
			close_fds(pipe_fd, io_fd, argc);
			execve(command, splited, env);
			perror("Error");
			exit(errno);
		}
		free(command);
		ft_split_free(splited);
		++index;
	}
	while (wait(NULL) < 0)
		;
	if (path)
		ft_split_free(path);
	close_fds(pipe_fd, io_fd, argc);
	return 0;
}