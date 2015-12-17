/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:46:25 by afillion          #+#    #+#             */
/*   Updated: 2015/11/30 18:28:24 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while ((unsigned char)str[i] < 33)
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) == 1)
	{
		sign = -sign;
		i++;
	}
	if (str[i] == '+' && ft_isdigit(str[i + 1]) == 1)
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * sign);
}
