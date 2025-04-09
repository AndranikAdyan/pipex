#include "libft.h"

char	*ft_join_free(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str1 && str1[i])
		str[j++] = str1[i++];
	i = 0;
	while (str2 && str2[i])
		str[j++] = str2[i++];
	str[j] = '\0';
	free(str1);
	return (str);
}