/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 07:21:11 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/23 17:30:49 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_NB_H
# define FT_CHECK_NB_H

int		check_nb_l(char **res, int i);
int		check_nb_r(char **res, int i);
int		check_nb_u(char **res, int j);
int		check_nb_d(char **res, int j);
int		check_doublon(char **res, int j);

#endif
