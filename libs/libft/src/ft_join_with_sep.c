/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_with_sep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:16:57 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/12 15:16:58 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_with_sep(char const *s1, char const *s2, char sep)
{
	char	*str;
	int		i;
	int		index;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	index = -1;
	while (s1[++i])
		str[++index] = s1[i];
	str[++index] = sep;
	i = -1;
	while (s2[++i])
		str[++index] = s2[i];
	str[++index] = '\0';
	return (str);
}
