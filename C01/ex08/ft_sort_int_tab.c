/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:51:16 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/18 06:18:36 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int a;
	int compteur1;
	int compteur2;
	int emplacement;

	compteur1 = 0;
	compteur2 = 0;
	while (compteur1 < size)
	{
		a = *(tab + compteur1);
		compteur2 = compteur1;
		while (compteur2 < size)
		{
			if (a >= *(tab + compteur2))
			{
				a = *(tab + compteur2);
				emplacement = compteur2;
			}
			compteur2 = compteur2 + 1;
		}
		ft_swap(tab + compteur1, tab + emplacement);
		compteur1 = compteur1 + 1;
	}
}
