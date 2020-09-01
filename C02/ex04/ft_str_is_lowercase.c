/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:03:08 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/14 16:09:04 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_alphabet_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_str_is_lowercase(char *str)
{
	char	c;
	int		compteur;

	compteur = 0;
	c = *str;
	while (c != '\0')
	{
		if (is_alphabet_low(c))
		{
			compteur++;
			c = *(str + compteur);
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
