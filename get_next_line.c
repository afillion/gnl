#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	char	buf[BUFF_SIZE + 1] = {0};
	int		ret;
	t_list	*lst;
	t_list	*new;

	*line = NULL;
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, line, BUFF_SIZE) > 0))
	{
		new = ft_lstnew(line, BUFF_SIZE);
		ft_lstadd_back(&lst, new);
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
