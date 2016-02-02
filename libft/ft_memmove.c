/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:43:33 by afillion          #+#    #+#             */
/*   Updated: 2015/11/30 17:29:36 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	*unmemcpy(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char*)dest;
	s2 = (char*)src;
	i = n;
	while (i > 0)
	{
		s1[i - 1] = s2[i - 1];
		i--;
	}
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest == NULL || src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, len);
	else
		unmemcpy(dest, src, len);
	return (dest);
}
