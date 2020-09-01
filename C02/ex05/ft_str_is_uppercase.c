/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:09:33 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/14 16:12:28 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_alphabet_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_str_is_uppercase(char *str)
{
	char	c;
	int		compteur;

	compteur = 0;
	c = *str;
	while (c != '\0')
	{
		if (is_alphabet_up(c))
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
