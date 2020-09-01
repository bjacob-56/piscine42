/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 09:08:33 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 06:39:35 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*a;
	int		compteur1;
	int		compteur2;
	int		emplacement;

	if (cmp == NULL)
		return ;
	compteur1 = 0;
	compteur2 = 0;
	while (tab[compteur1])
	{
		a = tab[compteur1];
		compteur2 = compteur1;
		while (tab[compteur2])
		{
			if (cmp(a, tab[compteur2]) >= 0)
			{
				a = tab[compteur2];
				emplacement = compteur2;
			}
			compteur2++;
		}
		tab[emplacement] = tab[compteur1];
		tab[compteur1++] = a;
	}
}
