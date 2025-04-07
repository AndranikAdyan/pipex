/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:48:45 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/07 20:39:29 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{
	if (argc < 4 || !validation(argc, argv))
	{
		printf("%ss\n", strerror(EINVAL));
		exit(EXIT_FAILURE);
	}
	return 0;
}
