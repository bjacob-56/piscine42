/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 08:43:26 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/23 17:30:15 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_check_nb.h"

void	ft_malloc(char ***res_temp)
{
	char	*ptr;
	int		i;
	int		j;

	(*res_temp) = malloc(sizeof(char*) * 6);
	i = 0;
	while (i < 4)
	{
		ptr = malloc(sizeof(char) * 5);
		j = 0;
		while (j < 4)
		{
			ptr[j] = '0';
			j++;
		}
		ptr[4] = '\0';
		(*res_temp)[i] = ptr;
		i++;
	}
}

void	stock_init(char **stock)
{
	int k;

	k = 0;
	while (k < 4)
	{
		(*stock)[k] = k + 1 + '0';
		k++;
	}
	(*stock)[4] = '\0';
}

int		check_nb(char **res, int ji, char *t_n, int lc)
{
	int j;

	j = ji / 10;
	if (check_doublon(res, j) == 0)
		return (0);
	if (lc / 10 == 0)
	{
		if (check_nb_l(res, (ji % 10)) > t_n[2 * (ji % 10) + 16] ||
				check_nb_r(res, (ji % 10)) + 4 - j < t_n[2 * (ji % 10) + 24])
			return (0);
	}
	else if (!(check_nb_l(res, (ji % 10)) == t_n[2 * (ji % 10) + 16]) ||
			!(check_nb_r(res, (ji % 10)) == t_n[2 * (ji % 10) + 24]))
		return (0);
	if (lc % 10 == 0)
	{
		if (!(check_nb_u(res, j) <= t_n[2 * j]) ||
				!(check_nb_d(res, j) + 4 - (ji % 10) >= t_n[2 * j + 8]))
			return (0);
	}
	else if (check_nb_u(res, j) != t_n[2 * j] ||
			check_nb_d(res, j) != t_n[2 * j + 8])
		return (0);
	return (1);
}

int		check_char_entree(char *str)
{
	int i;

	i = 0;
	while (i < 30)
	{
		if (str[i] >= '1' && str[i] <= '4'
				&& str[i + 1] == ' ')
			i = i + 2;
		else
			return (0);
	}
	if (str[i] >= '1' && str[i] <= '4'
			&& str[i + 1] == '\0')
		return (1);
	return (0);
}
