/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 18:21:39 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 17:48:53 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	switch_data(t_list **ptr, t_list **ptr1, t_list **begin_list)
{
	void	*data_t;

	data_t = (*ptr)->data;
	(*ptr)->data = (*ptr1)->data;
	(*ptr1)->data = data_t;
	*ptr = *begin_list;
	*ptr1 = (*ptr)->next;
}

void	find_first(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	t_list	*ptr1;
	void	*data_t;

	ptr = *begin_list;
	ptr1 = ptr->next;
	while (ptr1)
	{
		if (cmp(ptr->data, ptr1->data) > 0)
		{
			data_t = ptr->data;
			ptr->data = ptr1->data;
			ptr1->data = data_t;
		}
		ptr1 = ptr1->next;
	}
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	t_list	*ptr1;

	if (*begin_list == NULL)
		return ;
	find_first(begin_list, cmp);
	ptr = *begin_list;
	ptr1 = ptr->next;
	while (ptr1)
	{
		if (cmp(ptr->data, ptr1->data) > 0)
			switch_data(&ptr, &ptr1, begin_list);
		else
		{
			ptr = ptr->next;
			ptr1 = ptr1->next;
		}
	}
}
