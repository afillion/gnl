/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 17:17:48 by afillion          #+#    #+#             */
/*   Updated: 2015/12/31 17:17:50 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_join(char const *s1, char const *s2)
{
	char	*new;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	new[len] = '\0';
	free((void*)s1);
	return (new);
}

char				*ft_sub(char *mem)
{
	char *stock;

	stock = ft_strsub(mem, ft_strchr(mem, '\n') - mem + 1, \
			ft_strlen(ft_strchr(mem, '\n')));
	ft_strdel(&mem);
	return (stock);
}

int					get_next_line(int fd, char **line)
{
	static char		*mem[256];
	char			buff[BUFF_SIZE + 1];
	int				ret;

	ret = 1;
	if (BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!mem[fd])
		mem[fd] = ft_strnew(0);
	while (!(ft_strchr(mem[fd], '\n')) && (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = 0;
		mem[fd] = ft_join(mem[fd], buff);
	}
	*line = ft_strchr(mem[fd], '\n') ? ft_strsub(mem[fd], 0, \
			ft_strchr(mem[fd], '\n') - mem[fd] + 1) : ft_strdup(mem[fd]);
	if (ret)
		line[0][ft_strlen(*line) - 1] = 0;
	mem[fd] = ft_sub(mem[fd]);
	if (ret == 0)
		ft_strdel(&mem[fd]);
	return (ret == 0 ? 0 : 1);
}
