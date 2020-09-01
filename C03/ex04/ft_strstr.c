/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:59:55 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/17 19:54:15 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	long int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i_str;
	int i_f;
	int len_find;

	if (ft_strlen(to_find) == 0)
		return (str);
	len_find = ft_strlen(to_find);
	i_str = 0;
	i_f = 0;
	while (str[i_str])
	{
		while ((to_find[i_f] == str[i_str + i_f]) && to_find[i_f])
			i_f++;
		if (i_f == len_find)
			return (str + i_str);
		else
		{
			i_f = 0;
			i_str++;
		}
	}
	return (NULL);
}
