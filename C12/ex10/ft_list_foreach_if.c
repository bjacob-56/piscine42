/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:55:15 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/27 18:11:59 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list	*ptr;

	ptr = begin_list;
	while (ptr)
	{
		if ((*cmp)(ptr->data, data_ref) == 0)
			(*f)(ptr->data);
		ptr = ptr->next;
	}
}
