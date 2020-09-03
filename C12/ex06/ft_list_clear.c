/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 08:17:51 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/27 08:55:47 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*elem;

	while (begin_list)
	{
		(*free_fct)(begin_list->data);
		elem = begin_list;
		begin_list = begin_list->next;
		free(elem);
	}
}
