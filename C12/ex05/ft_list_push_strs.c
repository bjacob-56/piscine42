/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 07:07:29 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 06:49:52 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin;
	t_list	*elem;
	t_list	*elem_new;
	int		i;

	if (size == 0)
		return (NULL);
	i = 0;
	elem = NULL;
	while (i < size)
	{
		elem_new = ft_create_elem(strs[i++]);
		elem_new->next = elem;
		elem = elem_new;
	}
	begin = elem;
	return (begin);
}
