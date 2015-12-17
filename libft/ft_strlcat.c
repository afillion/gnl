/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:42:58 by afillion          #+#    #+#             */
/*   Updated: 2015/11/30 17:38:06 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*dest_cpy;
	const char	*src_cpy;
	size_t		i;
	size_t		dest_len;

	dest_cpy = dest;
	src_cpy = src;
	i = size;
	while (i-- != 0 && *dest_cpy != '\0')
		dest_cpy++;
	dest_len = dest_cpy - dest;
	i = size - dest_len;
	if (i == 0)
		return (dest_len + ft_strlen(src_cpy));
	while (*src_cpy != '\0')
	{
		if (i != 1)
		{
			*dest_cpy++ = *src_cpy;
			i--;
		}
		src_cpy++;
	}
	*dest_cpy = '\0';
	return (dest_len + (src_cpy - src));
}
