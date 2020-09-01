/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:07:33 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/30 16:15:11 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	ft_print_hundred(int nbr, t_match *tab)
{
	char	*word_l;
	char	*word_r;

	if (nbr / 100 > 0)
	{
		word_l = ft_get_word(nbr / 100, tab);
		ft_putstr(word_l);
		ft_putstr(" ");
		word_r = ft_get_word(100, tab);
		ft_putstr(word_r);
	}
}

void	ft_print_decade(int nbr, t_match *tab)
{
	char	*word_l;
	char	*word_r;

	if (nbr < 20 && nbr > 0)
	{
		word_l = ft_get_word(nbr, tab);
		ft_putstr(word_l);
	}
	else if (nbr >= 20)
	{
		word_l = ft_get_word(nbr - (nbr % 10), tab);
		ft_putstr(word_l);
		if (nbr % 10 && nbr / 10)
			ft_putstr("-");
		if (nbr % 10)
		{
			word_r = ft_get_word(nbr % 10, tab);
			ft_putstr(word_r);
		}
	}
}

void	ft_print_low_nbr(char *str, t_match *tab, int l_r, int index)
{
	int		nbr;
	char	*tronc;
	int		rang;

	rang = l_r % 100;
	l_r = l_r / 100;
	if (l_r < 4)
	{
		nbr = ft_atoi(str);
		if (rang < index && nbr > 0)
			write(1, " ", 1);
		ft_print_hundred(nbr, tab);
		if (nbr / 100 > 0 && nbr % 100 > 0)
			write(1, " and  ", 5);
		ft_print_decade(nbr % 100, tab);
		if (rang > 0 && nbr != 0)
			print_power(tab, rang);
	}
	else
	{
		tronc = ft_tronc(str, l_r, 3);
		ft_print_low_nbr(tronc, tab, (l_r - 3) * 100 + rang + 1, index);
		free(tronc);
		ft_print_low_nbr(str + l_r - 3, tab, 3 * 100 + rang, index);
	}
}

void	ft_print_nbr(char *number, t_match *tab)
{
	int		len;
	char	*word_z;
	int		index;

	len = 0;
	while (number[len])
		len++;
	index = (len - 1) / 3;
	if (len == 1 && number[0] == '0')
	{
		word_z = ft_get_word(0, tab);
		ft_putstr(word_z);
	}
	else
		ft_print_low_nbr(number, tab, len * 100, index);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		write(1, "Error", 5);
	else if (argc == 2)
	{
		if (check_input(argv[1]) == 1)
			ft_init_rush02(argv[1], "numbers.dict");
		else if (check_input(argv[1]) == 0)
			write(1, "Error", 5);
		else
			write(1, "Dict Error", 10);
	}
	else if (argc == 3)
	{
		if (check_input(argv[2]) == 1)
			ft_init_rush02(argv[2], argv[1]);
		else if (check_input(argv[2]) == 0)
			write(1, "Error", 5);
		else
			write(1, "Dict Error", 10);
	}
	else
		write(1, "Error", 5);
	write(1, "\n", 1);
	return (0);
}
