/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 09:47:15 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/15 16:04:35 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	c;
	int		compteur;

	c = *src;
	compteur = 0;
	while (c != '\0')
	{
		*(dest + compteur) = c;
		compteur++;
		c = *(src + compteur);
	}
	*(dest + compteur) = '\0';
	return (dest);
}
