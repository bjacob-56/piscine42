/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:05:40 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/02 07:20:52 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_switch_elem(t_list **elem, t_list **ptr)
{
	(*elem)->next = (*ptr)->next;
	(*ptr)->next = *elem;
	return (0);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	*ptr;
	int		res;

	res = 1;
	elem = ft_create_elem(data);
	if (*begin_list == NULL)
		*begin_list = elem;
	ptr = *begin_list;
	if (cmp(elem->data, (*begin_list)->data) < 0)
	{
		elem->next = *begin_list;
		*begin_list = elem;
		res = 0;
	}
	while (ptr->next && res)
	{
		if (cmp(elem->data, ptr->next->data) < 0)
			res = ft_switch_elem(&elem, &ptr);
		else
			ptr = ptr->next;
	}
	if (res && ptr != elem)
		ptr->next = elem;
}
