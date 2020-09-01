/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_dictionary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 08:31:47 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/30 16:15:56 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int	check_input(char *str)
{
	int i;

	i = 0;
	if (str[0] == '0' && str[1] == '\0')
		return (1);
	if (str[0] == '0' && str[1] != '\n')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (i > 39)
		return (-1);
	return (1);
}

int	ft_checkline(char *str, int *i)
{
	int		cpt_c;

	cpt_c = 0;
	if (str[*i] == '\n' || str[*i] == '\0')
		return (1);
	if (str[*i] < '0' || str[*i] > '9')
		return (0);
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == ':')
		(*i)++;
	else
		return (0);
	while (str[*i] >= ' ' && str[*i] <= '~')
		if (str[(*i)++] != ' ')
			cpt_c++;
	if ((str[*i] == '\n' || str[*i] == '\0') && cpt_c > 0)
		return (1);
	return (0);
}

int	check_line_dictionary(char *buf)
{
	int	*i;
	int	ind;
	int	res;

	res = 1;
	ind = 0;
	i = &ind;
	while (buf[*i] != 0)
	{
		res = ft_checkline(buf, i);
		if (res == 0)
			return (0);
		if (buf[*i])
		{
			(*i)++;
		}
	}
	return (1);
}
