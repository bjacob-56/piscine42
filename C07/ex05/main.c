/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 07:05:50 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/24 14:07:20 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int main()
{
	char *str = "abc, 1234;7895 def";
	char *charset = "";
	char **str_tab;
	int i = 0;
	
	str_tab = ft_split(str, charset);
	while (i < 2)
		printf("%s\n", str_tab[i++]);
	free(str_tab);
}
