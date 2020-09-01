/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 08:47:55 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/30 13:56:29 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

char	*ft_get_word(int n, t_match *tab)
{
	int		i;
	char	*st;

	st = ft_itoa(n);
	i = 0;
	while (tab[i].number)
	{
		if (ft_comp_str(tab[i].number, st))
		{
			free(st);
			return (tab[i].word);
		}
		i++;
	}
	free(st);
	return (NULL);
}

char	*ft_get_power(char *power, t_match *tab)
{
	int		i;

	i = 0;
	while (tab[i].number)
	{
		if (ft_comp_str(tab[i].number, power))
			return (tab[i].word);
		i++;
	}
	return (NULL);
}

char	*ft_power(int rang)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (2 + 3 * rang));
	i = 0;
	res[0] = '1';
	while (i < rang)
	{
		res[3 * i + 1] = '0';
		res[3 * i + 2] = '0';
		res[3 * i + 3] = '0';
		i++;
	}
	res[3 * i + 1] = '\0';
	return (res);
}

void	print_power(t_match *tab, int rang)
{
	char	*power;
	char	*word_p;

	power = ft_power(rang);
	word_p = ft_get_power(power, tab);
	ft_putstr(" ");
	ft_putstr(word_p);
	free(power);
}

char	*ft_tronc(char *str, int len, int l_remove)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (len - l_remove + 1));
	while (i < len - l_remove)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
