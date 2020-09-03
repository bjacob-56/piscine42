/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 08:19:55 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/16 16:48:37 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_first_line(int x)
{
	int compteur;

	ft_putchar('A');
	compteur = 0;
	while (compteur < x - 2)
	{
		ft_putchar('B');
		compteur++;
	}
	if (x > 1)
		ft_putchar('A');
}

void	print_middle_line(int x)
{
	int compteur;

	ft_putchar('\n');
	ft_putchar('B');
	compteur = 0;
	while (compteur < x - 2)
	{
		ft_putchar(' ');
		compteur++;
	}
	if (x > 1)
		ft_putchar('B');
}

void	print_last_line(int x)
{
	int compteur;

	ft_putchar('\n');
	ft_putchar('C');
	compteur = 0;
	while (compteur < x - 2)
	{
		ft_putchar('B');
		compteur++;
	}
	if (x > 1)
		ft_putchar('C');
}

void	rush(int x, int y)
{
	int compteur;

	compteur = 0;
	if (y <= 0 || x <= 0)
	{
		compteur = y - 2;
		y = 0;
	}
	else
		print_first_line(x);
	while (compteur < y - 2)
	{
		print_middle_line(x);
		compteur++;
	}
	if (y > 1)
		print_last_line(x);
}
