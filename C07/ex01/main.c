/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 05:24:14 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/20 15:19:30 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_range(int min, int max);

int main()
{
	int min = -250;
	int max = 400;
	int *tab;
	int i = 0;

	tab = ft_range(min, max);
	while (i < (max - min))
		printf("%i, ",tab[i++]);
}
