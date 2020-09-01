/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 08:47:36 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/24 14:07:03 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		check_base(char *base);

int		longueur_chaine_char(long nb, char *base)
{
	int		base_len;
	int		i;
	long	power;

	base_len = 0;
	while (base[base_len])
		base_len++;
	i = 2;
	power = base_len;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (power <= nb)
	{
		power *= base_len;
		i++;
	}
	return (i);
}

void	get_nbr_base(long nbr, char *base, char **str, int l_char)
{
	int base_len;
	int i;

	i = l_char - 2;
	base_len = 0;
	while (base[base_len])
		base_len++;
	(*str)[l_char - 1] = '\0';
	if (nbr < 0)
	{
		(*str)[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		(*str)[i] = base[0];
	while (nbr > 0)
	{
		(*str)[i] = base[nbr % base_len];
		nbr = nbr / base_len;
		i--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*res;
	int		longueur_char;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	longueur_char = longueur_chaine_char(nb, base_to);
	res = malloc(sizeof(char) * longueur_char);
	get_nbr_base(nb, base_to, &res, longueur_char);
	return (res);
}
