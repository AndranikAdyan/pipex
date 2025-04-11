/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:48:45 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/11 11:42:59 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		here_doc;

	here_doc = is_here_doc(argv);
	if (!validation(argc, argv))
		return (1);
	if (here_doc)
		here_doc_input(data, argv);
	data.pipe_fd = malloc_pipe_fd(argc);
	set_pipes(data.pipe_fd, argc, here_doc);
	data.path = get_paths(env);
	open_files(data.io_fd, argv[1], argv[argc - 1], here_doc);
	execute_cmd(data, argc, argv, env);
	while (wait(NULL) != -1)
		;
	free_pipe_fd(data.pipe_fd, argc);
	ft_split_free(data.path);
	return (0);
}
