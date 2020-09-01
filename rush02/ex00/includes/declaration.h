/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 08:34:16 by bjacob            #+#    #+#             */
/*   Updated: 2020/08/30 16:22:37 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATION_H
# define DECLARATION_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 4096

typedef struct		s_matching
{
	char	*number;
	char	*word;
}					t_match;

char				*ft_path_to_buf(char *path);
t_match				*ft_buf_to_tab(char *buf);
int					ft_init_rush02(char *number, char *path);

void				ft_print_nbr(char *number, t_match *tab);

int					check_input(char *str);
int					ft_checkline(char *str, int *i);
int					check_line_dictionary(char *buf);

int					ft_checkdouble_number(t_match *tab);
int					ft_checkdouble_word(t_match *tab);
int					ft_check_key(t_match *tab);

void				ft_putstr(char *str);
int					ft_comp_str(char *str1, char *str2);
char				*ft_itoa(int nbr);
int					ft_atoi(char *str);
void				ft_fill_nbr(char **res, int nbr, int rang);

char				*ft_tronc(char	*str, int len, int l_remove);
char				*ft_power(int rang);
char				*ft_get_power(char	*power, t_match *tab);
void				print_power(t_match *tab, int rang);
char				*ft_get_word(int n, t_match *tab);

int					is_printable(char c);
void				free_key_list(char ***tab);
void				free_dictionary(t_match **tab);

#endif
