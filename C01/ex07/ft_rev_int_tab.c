/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:41:42 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/13 18:49:57 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int compteur;
	int a;

	compteur = 0;
	while (compteur < (size / 2))
	{
		a = *(tab + compteur);
		*(tab + compteur) = *(tab + size - 1 - compteur);
		*(tab + size - 1 - compteur) = a;
		compteur = compteur + 1;
	}
}
