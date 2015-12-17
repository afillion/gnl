/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:21:52 by afillion          #+#    #+#             */
/*   Updated: 2015/11/29 18:24:19 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c < 0 || c > 255 || c == '\0')
		return (char*)(s + i);
	while (s[i] != (char)c && i >= 0)
		i--;
	if (i < 0)
		return (NULL);
	return (char*)(s + i);
}
