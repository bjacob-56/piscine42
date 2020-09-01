/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 07:26:05 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/23 17:30:19 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMP_H
# define FT_COMP_H

int		check_nb(char **res, int ji, char	*t_n, int lc);
void	stock_init(char **stock);
void	ft_malloc(char ***res_temp);
void	put_colonne(char **res, int i, char *t_n);
int		check_char_entree(char *str);

#endif
