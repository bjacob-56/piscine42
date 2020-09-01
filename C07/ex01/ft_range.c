/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 05:19:33 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/20 15:20:09 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	i = min;
	if (!(tab = malloc(sizeof(*tab) * (max - min))))
		return (NULL);
	while (i < max)
	{
		tab[i - min] = i;
		i++;
	}
	return (tab);
}
