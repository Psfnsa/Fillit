/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:26:48 by mabanciu          #+#    #+#             */
/*   Updated: 2018/01/18 16:29:33 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc(size)))
		return (NULL);
	while (i < (int)size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
