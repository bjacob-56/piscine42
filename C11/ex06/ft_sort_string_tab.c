/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 08:58:54 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/26 09:07:12 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	char	*a;
	int		compteur1;
	int		compteur2;
	int		emplacement;

	compteur1 = 0;
	compteur2 = 0;
	while (tab[compteur1])
	{
		a = tab[compteur1];
		compteur2 = compteur1;
		while (tab[compteur2])
		{
			if (ft_strcmp(a, tab[compteur2]) >= 0)
			{
				a = tab[compteur2];
				emplacement = compteur2;
			}
			compteur2++;
		}
		tab[emplacement] = tab[compteur1];
		tab[compteur1] = a;
		compteur1++;
	}
}
