/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:26:14 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/13 16:05:14 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_bis(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
}

void	print_temp(char x, char y)
{
	char s;
	char t;

	s = x;
	while (s <= '9')
	{
		t = y + 1;
		while (t <= '9')
		{
			ft_putchar_bis(x, y, s, t);
			if (s != '9' || t != '9')
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			t++;
		}
		s++;
	}
}

void	ft_print_tempo(int n, int cp, char debut)
{
	char	c;
	char	d;

	while (cp < n)
	{
		ft_putchar(debut);
		ft_print_tempo(debut + 1);

		ft_putchar(',');
		ft_putchar(' ');
		
	}

	return (cp + 1);
}

fit_print_combn(int n)
{

	while ()
	{
		int comp = 0;
		cp = ft_print_tempo(n, cp);
	}
	
}

int main()
{
	ft_print_combn(1);
}
