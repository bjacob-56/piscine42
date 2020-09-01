/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_str_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 08:54:05 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/30 13:59:55 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
		res = res * 10 + str[i++] - '0';
	return (res);
}

void	ft_fill_nbr(char **res, int nbr, int rang)
{
	if (nbr < 10)
		(*res)[rang] = nbr + '0';
	else
	{
		ft_fill_nbr(res, nbr % 10, rang);
		ft_fill_nbr(res, nbr / 10, rang - 1);
	}
}

char	*ft_itoa(int nbr)
{
	char	*res;
	int		len;
	int		compteur;

	if (nbr == 0 || nbr == 1)
	{
		res = malloc(sizeof(char) * 2);
		res[0] = nbr + '0';
		res[1] = '\0';
		return (res);
	}
	len = 1;
	compteur = 1;
	while (compteur <= nbr)
	{
		compteur = compteur * 10;
		len++;
	}
	res = malloc(sizeof(char) * len);
	ft_fill_nbr(&res, nbr, len - 2);
	res[len - 1] = '\0';
	return (res);
}

int		ft_comp_str(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}
