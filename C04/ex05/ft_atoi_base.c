/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:36:34 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/18 14:10:26 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		is_white_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
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
	int l_base;

	l_base = 0;
	while (base[l_base])
		l_base++;
	if (l_base <= 1)
		return (0);
	if (check_double_char(base) == 0)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || is_white_space(*base++))
			return (0);
	}
	return (1);
}

int		check_char_dans_base(char c, char *base)
{
	int	compteur;

	compteur = 0;
	if (check_base(base))
	{
		while (base[compteur])
		{
			if (c == base[compteur])
				return (compteur);
			compteur++;
		}
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int res;
	int signe;
	int l_base;
	int nbr;

	l_base = 0;
	while (base[l_base])
		l_base++;
	res = 0;
	signe = 1;
	while (is_white_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			signe = -signe;
	}
	while (check_char_dans_base(*str, base) >= 0)
	{
		nbr = check_char_dans_base(*str++, base);
		res = l_base * res + nbr;
	}
	return (signe * res);
}
