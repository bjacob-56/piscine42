/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:40:46 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/25 11:22:45 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*ptr;
	int		src_len;
	int		i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	ptr = malloc(sizeof(*src) * (src_len + 1));
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void				ft_free_all(int i, t_stock_str *res)
{
	int j;

	j = 0;
	while (j < i)
		free(res[j++].copy);
	free(res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	i = 0;
	res = malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == NULL)
		return (res);
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		if (res[i].copy == NULL)
		{
			ft_free_all(i, res);
			return (NULL);
		}
		i++;
	}
	res[i].str = 0;
	return (res);
}
