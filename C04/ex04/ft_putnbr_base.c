/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:12:10 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/18 16:39:06 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int		check_double_char(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (*str)
	{
		c = *str++;
		while (str[i])
		{
			if (str[i++] == c)
				return (0);
		}
		i = 0;
	}
	return (1);
}

int		check_base(char *base)
{
	if (ft_strlen(base) <= 1)
		return (0);
	if (check_double_char(base) == 0)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base++ == '-')
			return (0);
	}
	return (1);
}

void	print_int_min(long nbr, char *base)
{
	int base_len;

	if (check_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			print_int_min(-nbr, base);
		}
		else
		{
			base_len = ft_strlen(base);
			if (nbr < base_len)
				write(1, &base[nbr], 1);
			else
			{
				print_int_min(nbr / base_len, base);
				print_int_min(nbr % base_len, base);
			}
		}
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	print_int_min((long)nbr, base);
}
