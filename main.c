/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:09:16 by mabanciu          #+#    #+#             */
/*   Updated: 2018/01/19 15:25:06 by gscutaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solver_map(t_map *map, t_etris (*piese)[26], int k)
{
	int	x;
	int y;

	y = 0;
	if (k == g_piese)
		return (1);
	while (y < map->size - (*piese)[k].inalt + 1)
	{
		x = 0;
		while (x < map->size - (*piese)[k].lung + 1)
		{
			if (place(&(*piese)[k], map, x, y))
			{
				if (solver_map(map, piese, k + 1))
					return (1);
				else
					set_piese(&(*piese)[k], map, point_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*solver(t_etris (*piese)[26])
{
	t_map	*map;
	int		size;

	size = high_sqrt(g_piese * 4);
	map = map_new(size);
	while (!solver_map(map, piese, 0))
	{
		size++;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	t_etris piese[26];

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [input_file]\n");
		return (1);
	}
	if (!reader(argv[1], &piese))
	{
		write(1, "error\n", 6);
		return (0);
	}
	map = solver(&piese);
	print_map(map);
	free_map(map);
	return (0);
}
