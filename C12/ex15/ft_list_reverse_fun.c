/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 07:55:52 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 19:38:45 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

void	switch_data(t_list *ptr_r, t_list *ptr_l)
{
	void	*data_l;

	data_l = ptr_l->data;
	ptr_l->data = ptr_r->data;
	ptr_r->data = data_l;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*ptr_r;
	t_list	*ptr_l;
	int		n;
	int		i;
	int		j;

	if (begin_list == NULL)
		return ;
	ptr_r = begin_list;
	n = find_last(&ptr_r);
	j = 0;
	while (j < n / 2)
	{
		ptr_r = begin_list;
		ptr_l = begin_list;
		i = 0;
		while (i < n - 1 - j)
		{
			ptr_r = ptr_r->next;
			if (i++ < j)
				ptr_l = ptr_l->next;
		}
		switch_data(ptr_r, ptr_l);
		j++;
	}
}
