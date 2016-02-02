/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:15:19 by afillion          #+#    #+#             */
/*   Updated: 2015/12/03 20:00:06 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*backup;

	if (*alst == NULL || del == NULL)
		return ;
	tmp = *alst;
	while (tmp)
	{
		backup = tmp->next;
		ft_lstdelone(&tmp, (*del));
		tmp = backup;
	}
	*alst = NULL;
}
