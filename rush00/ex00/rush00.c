/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:10:49 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/16 16:56:23 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_first_line(int x)
{
	int compteur;

	ft_putchar('o');
	compteur = 0;
	while (compteur < x - 2)
	{
		ft_putchar('-');
		compteur++;
	}
	if (x > 1)
		ft_putchar('o');
}

void	print_middle_line(int x)
{
	int compteur;

	ft_putchar('\n');
	ft_putchar('|');
	compteur = 0;
	while (compteur < x - 2)
	{
		ft_putchar(' ');
		compteur++;
	}
	if (x > 1)
		ft_putchar('|');
}

void	print_last_line(int x)
{
	int compteur;

	ft_putchar('\n');
	ft_putchar('o');
	compteur = 0;
	while (compteur < x - 2)
	{
		ft_putchar('-');
		compteur++;
	}
	if (x > 1)
		ft_putchar('o');
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
