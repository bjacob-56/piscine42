/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:33:34 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/24 07:15:19 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
	char *str = "10";
//	-2147483648
	char *base_from = "0123456789";
	char *base_to = "abcdefghij";
	char *res;

	res = ft_convert_base(str, base_from, base_to);
	printf("%s\n", res);
}
