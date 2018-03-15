/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:48:11 by mabanciu          #+#    #+#             */
/*   Updated: 2018/01/19 14:57:10 by gscutaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int		g_piese;
typedef	struct	s_etris
{
	char	symbol;
	char	str[4][4];
	int		lung;
	int		inalt;
	int		contor;
}				t_etris;
typedef	struct	s_map
{
	int		size;
	char	**array;
}				t_map;
typedef	struct	s_point
{
	int x;
	int	y;
}				t_point;
int				reader(char *file, t_etris (*piece)[26]);
t_map			*map_new(int size);
int				putstring(char *str, int *i, int (*v)[4], int *r);
int				vecini(int *r, int *count, char *str, int (*v)[4]);
void			temp(t_etris *tetramino, char *str, int index);
void			overlap(char (*str)[4][4], int min_i, int min_j);
void			mutare(t_etris *piese);
char			*ft_strnew(size_t size);
void			*ft_memset(void *str, int i, size_t len);
void			min_max(char *str, t_point *min, t_point *max);
t_point			*point_new(int x, int y);
void			set_piese(t_etris *piese, t_map *map, t_point *point, char c);
int				place(t_etris *piese, t_map *map, int x, int y);
void			coordonate(char *str, t_etris *piese);
void			print_map(t_map *map);
void			free_map(t_map *map);
void			ft_putstr(char *str);
void			ft_memdel(void **ap);
void			*ft_memset(void *str, int i, size_t len);
char			*ft_strnew(size_t size);
void			*ft_memalloc(size_t size);
int				high_sqrt(int n);
t_map			*solver(t_etris (*piese)[26]);
int				solver_map(t_map *map, t_etris (*piese)[26], int k);
#endif
