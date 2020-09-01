/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 05:16:48 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/20 04:02:43 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

float	ft_heron(float nb, float an)
{
	return (0.5 * (an + nb / an));
}

int		ft_sqrt(int nb)
{
	int		racine;
	float	an;
	float	an_1;
	float	tampon;
	float	nb_d;

	nb_d = (float)nb;
	if (nb <= 0)
		return (0);
	an = nb_d;
	an_1 = ft_heron(nb_d, an);
	while (an - an_1 >= 1)
	{
		tampon = an_1;
		an_1 = ft_heron(nb_d, an_1);
		an = tampon;
	}
	racine = (int)an_1;
	if (racine * racine == nb)
		return (racine);
	else
		return (0);
}
