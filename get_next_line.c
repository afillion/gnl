#include "get_next_line.h"

static char		*ft_realloc(char **save, size_t n)
{
	char	*s;

	s = ft_strnew(n);
	if (s)
		ft_strncpy(s, *save, n);
	ft_strdel(save);
	return (s);
}

int				get_next_line(int const fd, char **line)
{
	char	buf[BUFF_SIZE + 1] = {0};
	int		ret;
	int		total;
	int		previous;
	char	*tmp;

	*line = NULL;
	previous = -1;
	total = 0;
	if (fd == -1)
		return (-1);
	if (fd == previous)
	{
		*line = ft_realloc(line, BUFF_SIZE);
		ft_strncpy(*line, buf, BUFF_SIZE);
		if ((tmp = ft_strchr(*line, '\n')) || (tmp = ft_strchr(*line, -1)))
		{
			*tmp = '\0';
			ft_strncpy(buf, tmp + 1, BUFF_SIZE);
			previous = fd;
			return (1);
		}
		previous = fd;
		return (0);
	}
	while ((ret = read(fd, line, BUFF_SIZE) > 0))
	{
		*line = ft_realloc(line, total + ret);
		ft_strncpy(*line + total, buf, ret);
		if ((tmp = ft_strchr(*line, '\n')) || (tmp = ft_strchr(*line, -1)))
		{
			*tmp = '\0';
			ft_strncpy(buf, tmp + 1, BUFF_SIZE);
			return (1);
		}
		total += ret;
	}
	return (0);
}

#include <stdlib.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	**line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, line);
	return (0);
}
