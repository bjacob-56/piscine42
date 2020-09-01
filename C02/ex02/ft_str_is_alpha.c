/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:22:40 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/16 12:12:11 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_alphabet(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_str_is_alpha(char *str)
{
	char	c;
	int		compteur;

	compteur = 0;
	c = *str;
	while (c != '\0')
	{
		if (is_alphabet(c))
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
