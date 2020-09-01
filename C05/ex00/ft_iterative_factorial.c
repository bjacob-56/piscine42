/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 04:08:41 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/19 04:23:00 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int res;

	res = 0;
	if (nb >= 0)
	{
		res = 1;
		while (nb > 1)
		{
			res = res * nb;
			nb = nb - 1;
		}
	}
	return (res);
}
