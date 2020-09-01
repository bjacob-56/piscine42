/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 05:24:14 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/20 16:03:48 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int main()
{
	int min = -250;
	int max = 400;
	int i = 0;
	int *range;
	int res;

	res = 0;
	res = ft_ultimate_range(&range, min, max);
	while (i < (max - min))
		printf("%i, ",range[i++]);
	printf("\n res = %i\n", res);

}
