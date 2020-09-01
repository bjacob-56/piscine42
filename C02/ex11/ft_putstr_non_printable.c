/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:50:56 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/17 16:29:50 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_encode_base(unsigned char c, char *base)
{
	char div;
	char mod;

	div = base[c / 16];
	mod = base[c % 16];
	write(1, "\\", 1);
	write(1, &div, 1);
	write(1, &mod, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*str_u;

	str_u = (unsigned char*)str;
	while (*str_u)
	{
		if (is_printable(*str_u))
			write(1, str_u, 1);
		else
		{
			ft_encode_base(*str_u, "0123456789abcdef");
		}
		str_u++;
	}
}
