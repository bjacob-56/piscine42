/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 05:31:04 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/20 16:04:01 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = min;
	*range = malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	while (i < max)
	{
		(*range)[i - min] = i;
		i++;
	}
	return (max - min);
}
