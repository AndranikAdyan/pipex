/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:48:45 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/09 19:36:52 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (!validation(argc))
		return (1);
	data.pipe_fd = malloc_pipe_fd(argc);
	set_pipes(data.pipe_fd, argc);
	data.path = get_paths(env);
	open_files(data.io_fd, argv[1], argv[argc - 1]);
	execute_cmd(data, argc, argv, env);
	close_fds(data.pipe_fd, data.io_fd, argc);
	free_pipe_fd(data.pipe_fd, argc);
	ft_split_free(data.path);
	return (0);
}
