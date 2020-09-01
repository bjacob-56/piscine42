/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:07:52 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/25 05:44:56 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

void				ft_putnbr(int nb)
{
	char	c;
	char	d;
	char	r;

	if (nb <= 9)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		d = nb / 10;
		r = (nb % 10) + '0';
		ft_putnbr(d);
		write(1, &r, 1);
	}
}

void				ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	write(1, "\n", 1);
}

int					ft_print_stock(struct s_stock_str *par, int i)
{
	t_stock_str	stock;
	char		*str;

	stock = par[i];
	str = stock.str;
	if (str != 0)
	{
		str = stock.str;
		ft_putstr(str);
		ft_putnbr(stock.size);
		write(1, "\n", 1);
		str = stock.copy;
		ft_putstr(str);
		return (1);
	}
	else
		return (0);
}

void				ft_show_tab(struct s_stock_str *par)
{
	int			i;
	int			fin;

	i = 0;
	fin = 1;
	while (fin)
	{
		fin = ft_print_stock(par, i);
		i++;
	}
}
