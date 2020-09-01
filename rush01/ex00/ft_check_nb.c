/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 06:33:09 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/23 17:30:51 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_comp.h"

int		check_nb_l(char **res, int i)
{
	int k;
	int j;
	int compteur;

	k = 3;
	compteur = 0;
	if (res[i][0] > '0')
		compteur++;
	while (k >= 1)
	{
		j = k - 1;
		while (j >= 0 && res[i][j] < res[i][k])
			j--;
		if (j == -1)
			compteur++;
		k--;
	}
	return (compteur + '0');
}

int		check_nb_r(char **res, int i)
{
	int k;
	int j;
	int compteur;

	k = 0;
	compteur = 0;
	if (res[i][3] > '0')
		compteur++;
	while (k <= 2)
	{
		j = k + 1;
		while (j <= 3 && res[i][j] < res[i][k])
			j++;
		if (j == 4)
			compteur++;
		k++;
	}
	return (compteur + '0');
}

int		check_nb_u(char **res, int j)
{
	int k;
	int i;
	int compteur;

	k = 3;
	compteur = 0;
	if (res[0][j] > '0')
		compteur++;
	while (k >= 1)
	{
		i = k - 1;
		while (i >= 0 && res[i][j] < res[k][j])
			i--;
		if (i == -1)
			compteur++;
		k--;
	}
	return (compteur + '0');
}

int		check_nb_d(char **res, int j)
{
	int k;
	int i;
	int compteur;

	k = 0;
	compteur = 0;
	if (res[3][j] > '0')
		compteur++;
	while (k <= 2)
	{
		i = k + 1;
		while (i <= 3 && res[i][j] < res[k][j])
			i++;
		if (i == 4)
			compteur++;
		k++;
	}
	return (compteur + '0');
}

int		check_doublon(char **res, int j)
{
	int		k;
	int		nb;
	char	*stock;

	k = 0;
	stock = malloc(sizeof(char) * 5);
	stock_init(&stock);
	while (k < 4)
	{
		nb = res[k][j] - '0';
		if (nb > 0 && stock[nb - 1] == -1)
		{
			free(stock);
			return (0);
		}
		stock[nb - 1] = -1;
		k++;
	}
	free(stock);
	return (1);
}
