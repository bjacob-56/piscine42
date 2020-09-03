/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:44:23 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 17:17:20 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_remove_elem(t_list **ptr_back, t_list **ptr,
		void (*free_fct)(void *))
{
	(*ptr_back)->next = (*ptr)->next;
	free_fct((*ptr)->data);
	free(*ptr);
	*ptr = (*ptr_back)->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*ptr;
	t_list	*ptr_back;

	if (*begin_list == NULL)
		return ;
	ptr = (*begin_list)->next;
	ptr_back = (*begin_list);
	while (ptr)
	{
		if (cmp(ptr->data, data_ref) == 0)
			ft_remove_elem(&ptr_back, &ptr, free_fct);
		else
		{
			ptr_back = ptr;
			ptr = ptr->next;
		}
	}
	if (cmp((*begin_list)->data, data_ref) == 0)
	{
		ptr = (*begin_list)->next;
		free_fct((*begin_list)->data);
		free(*begin_list);
		*begin_list = ptr;
	}
}
