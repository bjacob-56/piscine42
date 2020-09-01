/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 06:18:27 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/24 10:46:50 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		sum_tab(int *tab, int size)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < size)
	{
		res = res + tab[i];
		i++;
	}
	return (res);
}

void	str_concat(char **dest, char **src, int size, char *sep)
{
	int		l;
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	l = 0;
	while (l < size)
	{
		str = src[i++];
		k = 0;
		if (str != NULL)
		{
			while (str[k])
				(*dest)[j++] = str[k++];
			if (l++ < size - 1)
			{
				k = 0;
				while (sep[k])
					(*dest)[j++] = sep[k++];
			}
		}
	}
}

int		len_tab_char(char **strs, int *l_strs, int size)
{
	int l;
	int w_l;
	int nb_w;

	nb_w = 0;
	l = 0;
	while (l < size)
	{
		if (strs[l] != NULL)
		{
			w_l = str_len(strs[l]);
			l_strs[nb_w++] = w_l;
		}
		l++;
	}
	return (nb_w);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		l_strs[size];
	int		l;

	size = len_tab_char(strs, l_strs, size);
	if (size == 0)
	{
		res = malloc(sizeof(*res));
		*res = '\0';
		return (res);
	}
	l = sum_tab(l_strs, size) + (size - 1) * str_len(sep) + 1;
	if (!(res = malloc(sizeof(*res) * l)))
		return (NULL);
	res[l - 1] = '\0';
	str_concat(&res, strs, size, sep);
	return (res);
}
