/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:59:32 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/11 11:43:06 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_here_doc(char **argv)
{
	return (ft_strcmp(argv[1], "here_doc") == 0);
}

void	here_doc_input(t_data data, char **argv)
{
	char	*str;

	data.io_fd[0] = open(FILE_NAME, O_CREAT | O_TRUNC | O_RDWR, 0644);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		str = get_next_line(0);
		if (!str || ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(str);
			break ;
		}
		ft_putstr_fd(str, data.io_fd[0]);
		free(str);
	}
	close(data.io_fd[0]);
}
