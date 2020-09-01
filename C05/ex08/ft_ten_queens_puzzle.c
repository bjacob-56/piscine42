/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 06:10:19 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/19 08:18:23 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	tab_init(int tab[10][10])
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	copie_tab(int tab_dest[10][10], int tab_src[10][10])
{
	int i;
	int j;
	int nb_temp;
	int nb;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			nb_temp = tab_dest[i][j];
			nb = tab_src[i][j];
			tab_dest[i][j] = tab_src[i][j];
			j++;
		}
		i++;
	}
}

void	remplit_tab(int i, int j, int tab[10][10])
{
	int j_plus;
	int j_moins;
	int j_droit;
	int i_plus;
	int i_moins;

	i_moins = i + 1;
	i_plus = i + 1;
	i = i + 1;
	j_moins = j + 1;
	j_plus = j - 1;
	j_droit = j;
	while (j_plus >= 0 && i_plus < 10)
		tab[i_plus++][j_plus--] = 1;
	while (j_moins < 10 && i_moins < 10)
		tab[i_moins++][j_moins++] = 1;
	while (i < 10)
		tab[i++][j_droit] = 1;
}

void	ft_first_c(int i, int tab[10][10], char *res, int *ptr)
{
	int j;
	int tab_temp[10][10];

	if (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (tab[i][j] == 0)
			{
				res[i] = j + '0';
				copie_tab(tab_temp, tab);
				tab_temp[i][j] = 1;
				remplit_tab(i, j, tab_temp);
				ft_first_c(i + 1, tab_temp, res, ptr);
			}
			j++;
		}
	}
	else
	{
		while (*res)
			write(1, res++, 1);
		*ptr = *ptr + 1;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		tab[10][10];
	char	res[11];
	int		compteur;
	int		*ptr;

	tab_init(tab);
	res[10] = 10;
	compteur = 0;
	ptr = &compteur;
	ft_first_c(0, tab, res, ptr);
	return (compteur);
}
