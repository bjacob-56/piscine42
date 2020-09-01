/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 08:19:59 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/30 15:13:00 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int		ft_checkdouble_number(t_match *tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i].number != 0)
	{
		j = i + 1;
		while (tab[j].number != 0)
		{
			if (ft_comp_str(tab[i].number, tab[j].number) == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_checkdouble_word(t_match *tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i].word != 0)
	{
		j = i + 1;
		while (tab[j].word != 0)
		{
			if (ft_comp_str(tab[i].word, tab[j].word) == 1)
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

char	*ft_fill_small_str(int i)
{
	char	*str;

	str = NULL;
	if (i < 10)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = i + '0';
		str[1] = '\0';
	}
	else if (i < 100)
	{
		str = malloc(sizeof(char) * 3);
		str[0] = (i / 10) + '0';
		str[1] = (i % 10) + '0';
		str[2] = '\0';
	}
	else if (i == 100)
	{
		str = malloc(sizeof(char) * 4);
		str[0] = '1';
		str[1] = '0';
		str[2] = '0';
		str[3] = '\0';
	}
	return (str);
}

char	**ft_key_list(void)
{
	int		i;
	int		j;
	char	**res;

	res = malloc(sizeof(char*) * (42));
	if (!res)
		return (res);
	i = 0;
	while (i < 20)
	{
		res[i] = ft_fill_small_str(i);
		i++;
	}
	j = 20;
	while (j <= 100)
	{
		res[i++] = ft_fill_small_str(j);
		j = j + 10;
	}
	j = 1;
	while (i < 41)
		res[i++] = ft_power(j++);
	res[i] = 0;
	return (res);
}

int		ft_check_key(t_match *tab)
{
	int		i;
	int		j;
	int		comp;
	char	**key_list;

	key_list = ft_key_list();
	i = 0;
	while (key_list[i] != 0)
	{
		comp = 0;
		j = 0;
		while (tab[j].number != 0)
		{
			if (ft_comp_str(key_list[i], tab[j++].number) == 1)
				comp = 1;
		}
		if (comp == 0)
		{
			free_key_list(&key_list);
			return (0);
		}
		i++;
	}
	free_key_list(&key_list);
	return (1);
}
