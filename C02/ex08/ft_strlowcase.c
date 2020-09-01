/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:20:57 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/16 11:29:14 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		is_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strlowcase(char *str)
{
	char	c;
	int		compteur;

	compteur = 0;
	c = *str;
	while (c != '\0')
	{
		if (is_up(c))
			str[compteur] = c + 'a' - 'A';
		compteur++;
		c = str[compteur];
	}
	return (str);
}
