/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:27:07 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 13:22:20 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operateurs.h"
#include <unistd.h>
#include <stdio.h>

typedef int		(*t_fnctn_ptr)(int a, int b);

void			ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_fnctn_ptr		ft_find_op(char *str)
{
	t_fnctn_ptr	res[128];
	t_fnctn_ptr	ptr;
	int			i;

	i = str[0];
	res['+'] = &ft_plus;
	res['-'] = &ft_moins;
	res['*'] = &ft_fois;
	res['/'] = &ft_div;
	res['%'] = &ft_mod;
	ptr = res[i];
	return (ptr);
}

int				is_operateur(char *str)
{
	int		length;
	char	c;

	length = 0;
	while (str[length])
		length++;
	if (length == 1)
	{
		c = str[0];
		if (c == '+' || c == '-' || c == '*'
				|| c == '/' || c == '%')
			return (1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	int			a;
	int			b;
	t_fnctn_ptr	ptr;

	if (argc == 4 && is_operateur(argv[2]))
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		ptr = ft_find_op(argv[2]);
		if (argv[2][0] == '/' && b == 0)
			ft_putstr("Stop : division by zero\n");
		else if (argv[2][0] == '%' && b == 0)
			ft_putstr("Stop : modulo by zero\n");
		else
		{
			ft_putnbr((*ptr)(a, b));
			write(1, "\n", 1);
		}
	}
	else if (argc == 4)
		write(1, "0\n", 2);
	return (0);
}
