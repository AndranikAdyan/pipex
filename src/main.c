/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:48:45 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/08 19:19:18 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	if (!validation(argc, argv))
		return (1);
	char *command = ret_command(env, argv[2]);
	ft_putendl_fd(command, 1);
	free(command);
	(void)argv;
	return 0;
}
