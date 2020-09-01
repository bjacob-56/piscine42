/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:08:37 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/30 16:18:14 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	free_key_list(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i] != 0)
		free((*tab)[i++]);
	free(*tab);
}

void	free_dictionary(t_match **tab)
{
	int	i;

	i = 0;
	while ((*tab)[i].number)
	{
		free((*tab)[i].number);
		free((*tab)[i++].word);
	}
	free(*tab);
}

int		is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int		ft_init_rush02(char *number, char *path)
{
	char	*buf;
	t_match	*tab;

	buf = ft_path_to_buf(path);
	if (!buf)
		return (0);
	if (check_line_dictionary(buf) == 0)
	{
		free(buf);
		write(1, "Dict Error", 10);
		return (0);
	}
	tab = ft_buf_to_tab(buf);
	free(buf);
	if (ft_checkdouble_number(tab) != 1 || ft_checkdouble_word(tab) != 1
			|| ft_check_key(tab) != 1)
	{
		free_dictionary(&tab);
		write(1, "Dict Error", 10);
		return (0);
	}
	ft_print_nbr(number, tab);
	free_dictionary(&tab);
	return (0);
}
