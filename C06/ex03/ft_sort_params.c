/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 09:02:49 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/19 10:32:57 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

void	ft_sort_str_tab(char **tab, int size)
{
	char	*a;
	int		compteur1;
	int		compteur2;
	int		emplacement;

	compteur1 = 0;
	compteur2 = 0;
	while (compteur1 < size)
	{
		a = tab[compteur1];
		compteur2 = compteur1;
		while (compteur2 < size)
		{
			if (ft_strcmp(a, tab[compteur2]) >= 0)
			{
				a = tab[compteur2];
				emplacement = compteur2;
			}
			compteur2++;
		}
		tab[emplacement] = tab[compteur1];
		tab[compteur1] = a;
		compteur1++;
	}
}

int		main(int argc, char **argv)
{
	int compteur;

	ft_sort_str_tab(argv + 1, argc - 1);
	compteur = 1;
	while (compteur < argc)
	{
		ft_putstr(argv[compteur++]);
		ft_putchar('\n');
	}
}
