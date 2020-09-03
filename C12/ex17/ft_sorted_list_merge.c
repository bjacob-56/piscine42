/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 10:25:26 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/02 08:28:31 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_switch_elem(t_list **elem, t_list **ptr)
{
	(*elem)->next = (*ptr)->next;
	(*ptr)->next = *elem;
	return (0);
}

void	ft_sorted_list_insert(t_list **begin_list, t_list **elem, int (*cmp)())
{
	t_list	*ptr;
	int		res;

	res = 1;
	if (*begin_list == NULL)
	{
		*begin_list = *elem;
		return ;
	}
	ptr = *begin_list;
	if (cmp((*elem)->data, (*begin_list)->data) < 0)
	{
		(*elem)->next = *begin_list;
		*begin_list = *elem;
		res = 0;
	}
	while (ptr->next && res)
	{
		if (cmp((*elem)->data, ptr->next->data) < 0)
			res = ft_switch_elem(elem, &ptr);
		else
			ptr = ptr->next;
	}
	if (res && ptr != *elem)
		ptr->next = *elem;
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	t_list	*ptr;
	t_list	*ptr2;

	ptr = begin_list2;
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		ptr = NULL;
	}
	while (ptr)
	{
		ptr2 = ptr->next;
		ft_sorted_list_insert(begin_list1, &ptr, cmp);
		ptr = ptr2;
	}
}
