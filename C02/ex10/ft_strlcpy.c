/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:07:44 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/15 18:34:15 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int				str_len(char *str)
{
	char	c;
	int		compteur;

	c = *str;
	compteur = 0;
	while (c != '\0')
	{
		compteur++;
		c = *(str + compteur);
	}
	return (compteur);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char				c;
	unsigned int		compteur;
	unsigned int		len_src;

	len_src = str_len(src);
	c = *src;
	compteur = 0;
	if (size == 0)
		return (len_src);
	else
	{
		while (c != '\0' && (compteur < size - 1))
		{
			*(dest + compteur) = c;
			compteur++;
			c = *(src + compteur);
		}
		*(dest + compteur) = '\0';
		return (len_src);
	}
}
