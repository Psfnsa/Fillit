/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:12:48 by mabanciu          #+#    #+#             */
/*   Updated: 2018/01/18 16:23:00 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	overlap(char (*str)[4][4], int min_i, int min_j)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*str)[min_i + i][min_j + j] == '#')
			{
				(*str)[min_i + i][min_j + j] = '.';
				(*str)[i][j] = '#';
			}
			j++;
		}
		i++;
	}
}

int		high_sqrt(int n)
{
	int	size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void**)&(map->array[i]));
		i++;
	}
	ft_memdel((void**)&(map->array));
	ft_memdel((void**)&map);
}
