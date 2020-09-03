/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 06:55:59 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/27 07:04:35 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (NULL);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*last_elem;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (*begin_list == NULL)
		*begin_list = elem;
	else
	{
		last_elem = ft_list_last(*begin_list);
		last_elem->next = elem;
	}
}
