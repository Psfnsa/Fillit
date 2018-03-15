/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:39:14 by mabanciu          #+#    #+#             */
/*   Updated: 2018/01/19 15:24:51 by gscutaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		putstring(char *str, int *i, int (*v)[4], int *r)
{
	while (str[*i] == '.' || str[*i] == '#' || str[*i] == '\n')
	{
		if (str[*i] == '#')
		{
			(*v)[*r] = *i;
			(*r)++;
			if ((*r) > 4)
				return (0);
		}
		(*i)++;
	}
	if ((*i) == 21 && str[20] != '\n')
		return (0);
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (0);
	if ((*i) < 20)
		return (0);
	return (1);
}

int		vecini(int *r, int *count, char *str, int (*v)[4])
{
	int	k;

	k = 0;
	while (--(*r) >= 0)
	{
		if ((k = (*v)[*r] - 5) >= 0)
			if (str[k] == '#')
				(*count)++;
		if ((k = (*v)[*r] + 5) < 19)
			if (str[k] == '#')
				(*count)++;
		if ((k = (*v)[*r] - 1) >= 0)
			if (str[k] == '#')
				(*count)++;
		if ((k = (*v)[*r] + 1) < 19)
			if (str[k] == '#')
				(*count)++;
	}
	if ((*count) == 6 || (*count) == 8)
		return (1);
	return (0);
}

void	temp(t_etris *tetramino, char *str, int index)
{
	int	i;
	int	j;

	(*tetramino).symbol = index + 'A';
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*tetramino).str[i][j] = *str;
			str++;
			j++;
		}
		str++;
		i++;
	}
}

void	mutare(t_etris *piese)
{
	int	min_i;
	int	min_j;
	int i;
	int j;

	i = 0;
	min_i = 3;
	min_j = 3;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*piese).str[i][j] == '#')
			{
				if (i < min_i)
					min_i = i;
				if (j < min_j)
					min_j = j;
			}
			j++;
		}
		i++;
	}
	overlap(&(*piese).str, min_i, min_j);
}

int		reader(char *file, t_etris (*piese)[26])
{
	int		v[4];
	int		i[7];
	char	str[21];

	i[4] = 0;
	i[3] = open(file, O_RDONLY);
	while ((i[5] = read(i[3], str, 21)) >= 20)
	{
		i[1] = 0;
		i[0] = 0;
		i[2] = 0;
		if (!putstring(str, &i[0], &v, &i[1]))
			return (0);
		if (!vecini(&i[1], &i[2], str, &v))
			return (0);
		temp(&(*piese)[i[4]], str, i[4]);
		mutare(&(*piese)[i[4]]);
		coordonate(str, &(*piese)[i[4]++]);
		i[6] = i[5];
	}
	g_piese = i[4];
	if (!(i[5] != 0 || i[6] != 20) && !((str[i[0]] != '.' &&
					str[i[0]] != '#' && str[i[0]] >= 'A' && str[i[0]] <= 'Z')))
		return (1);
	return (0);
}
