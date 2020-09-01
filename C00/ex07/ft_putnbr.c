/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 12:48:12 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/13 21:12:26 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		write_moins(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	char	c;
	int		d;
	int		r;

	if (nb == -2147483648)
	{
		ft_putnbr(-214748364);
		ft_putnbr(8);
	}
	else
	{
		nb = write_moins(nb);
		if (nb <= 9)
		{
			c = nb + '0';
			ft_putchar(c);
		}
		else
		{
			d = nb / 10;
			r = (nb % 10) + '0';
			ft_putnbr(d);
			ft_putchar(r);
		}
	}
}
