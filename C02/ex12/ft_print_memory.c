/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:07:23 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/17 17:51:47 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_encode_write(long nb, char *base, char *tab, int rang)
{
	char c;

	if (nb >= 16)
	{
		ft_encode_write(nb / 16, base, tab, rang - 1);
		ft_encode_write(nb % 16, base, tab, rang);
	}
	else
	{
		c = base[nb];
		tab[rang] = c;
	}
}

void	ft_encode(unsigned char c, char *base)
{
	char div;
	char mod;

	div = base[c / 16];
	mod = base[c % 16];
	write(1, &div, 1);
	write(1, &mod, 1);
}

void	ft_print_hexa(void *addr, int i_ligne, unsigned int size)
{
	unsigned char	c;
	int				j;
	unsigned char	*str;

	str = (unsigned char*)addr;
	j = -1;
	c = str[0];
	while (j++ < 15)
	{
		if ((j + 1) / 2 == j / 2)
			write(1, " ", 1);
		c = str[j + i_ligne * 16];
		if ((unsigned int)j + i_ligne * 16 >= size)
			write(1, "  ", 2);
		else
			ft_encode(c, "0123456789abcdef");
	}
}

void	ft_print_char_line(void *addr, int i_ligne, unsigned int size)
{
	unsigned char	*str;
	unsigned char	c;
	int				j;

	write(1, " ", 1);
	str = (unsigned char *)addr;
	j = -1;
	while (j++ < 15)
	{
		c = str[j + i_ligne * 16];
		if ((unsigned int)j + i_ligne * 16 >= size)
			;
		else
		{
			if (c >= 32 && c <= 126)
				write(1, &c, 1);
			else
				write(1, ".", 1);
			c = str[j + i_ligne * 16];
		}
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*str;
	unsigned int	i_ligne;
	unsigned char	c;
	char			tab[16];
	int				i_tab;

	i_tab = -1;
	while (i_tab++ < 16)
		tab[i_tab] = '0';
	c = ':';
	if (size == 0)
		return (addr);
	str = (unsigned char *)addr;
	i_ligne = 0;
	while (i_ligne * 16 < size)
	{
		ft_encode_write((long)&str[i_ligne * 16], "0123456789abcdef", tab, 15);
		write(1, &tab, 16);
		write(1, &c, 1);
		ft_print_hexa(addr, i_ligne, size);
		ft_print_char_line(addr, i_ligne, size);
		write(1, "\n", 1);
		i_ligne++;
	}
	return (addr);
}
