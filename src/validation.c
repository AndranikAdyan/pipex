/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:49:55 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/07 20:36:19 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static inline int	is_exist(char *input, char *output)
{
	return (!access(input, F_OK | R_OK) && !access(output, F_OK | W_OK));
}

int	validation(int argc, char *argv[])
{
	return (is_exist(argv[1], argv[argc - 1]));
}