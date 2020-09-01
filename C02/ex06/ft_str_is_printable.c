/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:16:43 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/15 18:47:10 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

int	ft_str_is_printable(char *str)
{
	char	c;
	int		compteur;

	compteur = 0;
	c = *str;
	while (c != '\0')
	{
		if (is_printable(c))
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
