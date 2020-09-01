/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 09:48:05 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/24 14:01:55 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		c_in_s(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int		get_nb_words(char *str, char *charset)
{
	int		i;
	int		nb_w;

	i = 1;
	nb_w = 0;
	if (!str[0])
		return (0);
	while (str[i])
	{
		if (c_in_s(str[i], charset))
		{
			if (!c_in_s(str[i - 1], charset))
				nb_w++;
		}
		i++;
	}
	if (!c_in_s(str[i - 1], charset))
		nb_w++;
	return (nb_w);
}

char	*ft_malloc_ptr(int i, int *j, char *str, char *charset)
{
	char	*ptr;

	*j = 0;
	while (!c_in_s(str[i + *j], charset) && str[i + *j])
		(*j)++;
	ptr = malloc(sizeof(char) * (*j + 1));
	*j = 0;
	while (str[i + *j] && !c_in_s(str[i + *j], charset))
		ptr[(*j)++] = str[i + *j];
	ptr[(*j)] = '\0';
	return (ptr);
}

void	sep_str_in_tab(char *str, char *charset, char ***str_tab, int *j)
{
	int		i;
	char	*ptr;
	int		new_w;
	int		i_words;

	new_w = 1;
	i = 0;
	i_words = 0;
	while (str[i])
	{
		if (!c_in_s(str[i], charset) && new_w)
		{
			ptr = ft_malloc_ptr(i, j, str, charset);
			new_w = 0;
			i = i + *j;
			(*str_tab)[i_words++] = ptr;
		}
		else if (c_in_s(str[i++], charset))
			new_w = 1;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**str_tab;
	int		nb_w;
	int		*j;
	int		i;

	i = 0;
	j = &i;
	str_tab = 0;
	nb_w = get_nb_words(str, charset);
	if (nb_w == 0)
	{
		str_tab = malloc(sizeof(char*));
		str_tab[0] = 0;
		return (str_tab);
	}
	str_tab = malloc(sizeof(char*) * (nb_w + 1));
	sep_str_in_tab(str, charset, &str_tab, j);
	str_tab[nb_w] = 0;
	return (str_tab);
}
