/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 04:44:16 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/25 11:20:47 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);

int main()
{
	char	*str[4] = {"", "123", "ef", "56789"};
	int		size = 4;
//	char	*str[0] = {};
//	int		size = 0;
	t_stock_str	*res;

	res = ft_strs_to_tab(size, str);

//	printf("%s\n\n", str[4]);

	res[1].copy = "adadadadadadada";

	ft_show_tab(res);
}
