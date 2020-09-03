/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 08:57:20 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/27 09:11:43 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	if (begin_list == NULL)
		return (NULL);
	i = 0;
	while (begin_list && i++ < nbr)
	{
		begin_list = begin_list->next;
	}
	return (begin_list);
}
