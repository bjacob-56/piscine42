/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:33:18 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/15 12:18:44 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		is_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strupcase(char *str)
{
	char	c;
	int		compteur;

	compteur = 0;
	c = *str;
	while (c != '\0')
	{
		if (is_low(c))
		{
			*(str + compteur) = c - 'a' + 'A';
		}
		compteur++;
		c = *(str + compteur);
	}
	return (str);
}
