/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dictionary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 05:52:20 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/30 16:01:36 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int		ft_fill_ligne_1(char *buf, t_match **tab, int *index)
{
	char	*number;
	int		j;
	int		len;

	j = 0;
	len = 0;
	while (buf[j + len] >= '0' && buf[j + len] <= '9')
		len++;
	number = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (buf[j] >= '0' && buf[j] <= '9')
		number[len++] = buf[j++];
	number[len] = '\0';
	while (buf[j] == ' ')
		j++;
	if (buf[j] == ':')
		j++;
	else
		;
	(*tab)[*index].number = number;
	return (j);
}

int		ft_fill_ligne_2(char *buf, t_match **tab, int *index)
{
	char	*word;
	int		j;
	int		len;

	j = 0;
	len = 0;
	while (buf[j] == ' ')
		j++;
	len = 0;
	while (is_printable(buf[j + len]))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	len = 0;
	while (is_printable(buf[j]))
		word[len++] = buf[j++];
	word[len] = '\0';
	while (buf[j] && buf[j] != '\n')
		j++;
	(*tab)[*index].word = word;
	(*index)++;
	return (j);
}

int		ft_fill_tab(char *buf, t_match **tab, int size)
{
	int		i;
	int		ind;
	int		*index;

	ind = 0;
	index = &ind;
	i = 0;
	while (*index < size && buf[i])
	{
		if (buf[0] == '\n')
			buf++;
		else
		{
			i = ft_fill_ligne_1(buf, tab, index);
			buf = buf + i;
			i = ft_fill_ligne_2(buf, tab, index);
			buf = buf + i + 1;
		}
	}
	return (*index);
}

char	*ft_path_to_buf(char *path)
{
	char	*buf;
	int		fd;
	int		i;

	buf = malloc(BUF_SIZE + 1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		write(1, "Dict Error", 10);
		return (NULL);
	}
	i = read(fd, buf, BUF_SIZE);
	if (i == -1)
	{
		close(fd);
		free(buf);
		write(1, "Dict Error", 10);
		return (NULL);
	}
	buf[i] = '\0';
	close(fd);
	return (buf);
}

t_match	*ft_buf_to_tab(char *buf)
{
	int		i;
	int		size;
	t_match	*tab;

	i = 0;
	size = 0;
	while (buf[i])
		if (buf[i++] == '\n')
			size++;
	tab = malloc(sizeof(t_match) * (size + 1));
	size = ft_fill_tab(buf, &tab, size);
	tab[size].number = NULL;
	return (tab);
}
