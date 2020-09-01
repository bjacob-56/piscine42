/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:03:12 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/15 19:03:40 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char				c;
	unsigned int		compteur;

	c = *src;
	compteur = 0;
	while (compteur < n)
	{
		if (c != '\0')
		{
			*(dest + compteur) = c;
			compteur++;
			c = *(src + compteur);
		}
		else
		{
			*(dest + compteur) = '\0';
			compteur++;
		}
	}
	return (dest);
}
