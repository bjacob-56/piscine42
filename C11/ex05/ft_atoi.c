/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:13:13 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/26 07:13:25 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_white_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int res;
	int signe;

	res = 0;
	signe = 1;
	while (is_white_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			signe = -signe;
	}
	while (is_numeric(*str))
		res = 10 * res + (*str++ - '0');
	return (signe * res);
}
