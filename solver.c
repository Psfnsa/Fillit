/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:25:04 by mabanciu          #+#    #+#             */
/*   Updated: 2018/01/18 16:26:38 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	*point_new(int x, int y)
{
	t_point *point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

void	set_piese(t_etris *piese, t_map *map, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < piese->lung)
	{
		j = 0;
		while (j < piese->inalt)
		{
			if (piese->str[j][i] == '#')
				map->array[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void**)&point);
}

int		place(t_etris *piese, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < piese->lung)
	{
		j = 0;
		while (j < piese->inalt)
		{
			if (piese->str[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piese(piese, map, point_new(x, y), piese->symbol);
	return (1);
}

void	coordonate(char *str, t_etris *piese)
{
	t_point	*min;
	t_point	*max;
	int		i;

	min = point_new(3, 3);
	max = point_new(0, 0);
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
	piese->lung = max->x - min->x + 1;
	piese->inalt = max->y - min->y + 1;
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char**)ft_memalloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
