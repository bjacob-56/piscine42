/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 09:14:00 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 18:18:42 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>

int		find_last(t_list **ptr)
{
	int	n;

	n = 1;
	while ((*ptr)->next)
	{
		*ptr = (*ptr)->next;
		n++;
	}
	return (n);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*ptr;
	t_list	*begin;
	int		n;
	int		i;

	if (*begin_list == NULL)
		return ;
	ptr = *begin_list;
	n = find_last(&ptr);
	begin = ptr;
	while (n > 1)
	{
		ptr = *begin_list;
		i = 0;
		while (i < n - 2)
		{
			i++;
			ptr = ptr->next;
		}
		ptr->next->next = ptr;
		n--;
	}
	(*begin_list)->next = NULL;
	*begin_list = begin;
}
