/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:20:03 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/13 18:08:35 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_data *data, char **argv, int index)
{
	data->splited = ft_split(argv[index], ' ');
	if (!data->splited || !data->splited[0])
	{
		data->command = NULL;
		return ;
	}
	data->command = ret_command(data->splited[0], data->path);
}

void	free_data(t_data *data)
{
	free(data->command);
	ft_split_free(data->splited);
}
