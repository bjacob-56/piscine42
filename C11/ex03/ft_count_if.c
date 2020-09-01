/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 06:21:59 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/26 06:26:07 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int	res;

	i = 0;
	res = 0;
	while (i < length)
		if ((*f)(tab[i++]) != 0)
			res++;
	return (res);
}
