/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 18:17:16 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 08:38:39 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *ptr;

	ptr = *begin_list1;
	if (!ptr)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = begin_list2;
}
