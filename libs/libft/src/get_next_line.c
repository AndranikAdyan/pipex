#include "libft.h"

static char	*ft_cutstr(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		s[i] = str[i];
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static void	read_line(int fd, char **str)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(*str);
			*str = NULL;
			break ;
		}
		buf[bytes] = '\0';
		if (bytes == 0)
			break ;
		*str = ft_join_free(*str, buf);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buf);
}

static char	*ft_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!remainder)
		return (NULL);
	j = 0;
	while (str[++i])
		remainder[j++] = str[i];
	remainder[j] = 0;
	free(str);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_line(fd, &str);
	s = ft_cutstr(str);
	if (s && !*s)
	{
		free(s);
		free(str);
		str = NULL;
		s = NULL;
		return (NULL);
	}
	str = ft_remainder(str);
	return (s);
}