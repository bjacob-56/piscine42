/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 05:37:10 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/23 17:31:21 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_check_nb.h"
#include "ft_comp.h"

void	print_solution(char **res)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &(res[i][j++]), 1);
			if (j <= 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	put_ligne(char **res, int i, int j, char *t_n)
{
	int		k;

	if (*res[4] && j < 4)
	{
		if (check_nb(res, j * 10 + i, t_n, 0 * 10 + 0))
		{
			k = 0;
			while (k < 4)
			{
				if (res[5][k] != '0')
				{
					res[i][j] = res[5][k];
					res[5][k] = '0';
					if (*res[4] &&
							check_nb(res, j * 10 + i, t_n, 0 * 10 + (i == 3)))
						put_ligne(res, i, j + 1, t_n);
					res[5][k] = k + 1 + '0';
					res[i][j] = '0';
				}
				k++;
			}
		}
	}
	else if (*res[4] && check_nb(res, 3 * 10 + i, t_n, 1 * 10 + (i == 3)))
		put_colonne(res, i + 1, t_n);
}

void	put_colonne(char **res, int i, char *t_n)
{
	int		j;

	stock_init(&res[5]);
	j = 0;
	if (*res[4])
	{
		if (i == 4)
		{
			*res[4] = 0;
			print_solution(res);
		}
		else
		{
			put_ligne(res, i, 0, t_n);
		}
	}
}

void	ft_find_solution(char *t_n)
{
	char	*stock;
	char	**res;
	char	*ptr;

	ptr = malloc(sizeof(char));
	*ptr = 1;
	stock = malloc(sizeof(char) * 5);
	stock_init(&stock);
	ft_malloc(&res);
	res[4] = ptr;
	res[5] = stock;
	put_colonne(res, 0, t_n);
	if (*ptr)
	{
		write(1, "Error\n", 6);
	}
	free(ptr);
	free(stock);
	free(res);
}

int		main(int argc, char **argv)
{
	char *str;

	if (argc == 2)
	{
		(void)argc;
		str = argv[1];
		if (check_char_entree(str))
			ft_find_solution(str);
		else
			write(1, "Error\n", 6);
	}
	else
	{
		(void)argc;
		write(1, "Error\n", 6);
	}
	return (0);
}
