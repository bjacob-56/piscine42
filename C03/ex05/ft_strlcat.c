/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:34:26 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/20 12:45:13 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	long int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i_dest;
	unsigned int	i_src;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i_dest = 0;
	i_src = 0;
	if (dest_len >= size)
		return (size + src_len);
	while (dest[i_dest])
		i_dest++;
	while (src[i_src] && (i_src + i_dest < size - 1))
	{
		dest[i_dest + i_src] = src[i_src];
		i_src++;
	}
	dest[i_dest + i_src] = '\0';
	return (dest_len + src_len);
}
