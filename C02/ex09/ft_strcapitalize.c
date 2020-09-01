/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:26:11 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/16 15:27:55 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		is_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int		is_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int		is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	c;
	int		compteur;
	int		first_l;

	compteur = 0;
	first_l = 1;
	c = *str;
	while (c != '\0')
	{
		if (is_alphanumeric(c) == 0)
		{
			first_l = 1;
		}
		else
		{
			if (first_l && is_low(c))
				*(str + compteur) = c - 'a' + 'A';
			if (first_l == 0 && is_up(c))
				*(str + compteur) = c + 'a' - 'A';
			first_l = 0;
		}
		compteur++;
		c = *(str + compteur);
	}
	return (str);
}
