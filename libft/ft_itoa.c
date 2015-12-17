/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:02:55 by afillion          #+#    #+#             */
/*   Updated: 2015/12/04 11:07:28 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_sub(unsigned int n, int len, int pos, char **str)
{
	if (n >= 10)
		pos = ft_itoa_sub(n / 10, len + 1, pos, str);
	else
		*str = ft_strnew(len);
	if (!*str)
		return (0);
	(*str)[pos] = (n % 10) + '0';
	return (pos + 1);
}

char			*ft_itoa(int n)
{
	char	*str;

	if (n < 0)
	{
		ft_itoa_sub(-n, 2, 1, &str);
		if (str)
			str[0] = '-';
	}
	else
		ft_itoa_sub(n, 1, 0, &str);
	return (str);
}
