/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:15:56 by mabanciu          #+#    #+#             */
/*   Updated: 2018/01/11 16:32:52 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *str, int i, size_t len)
{
	unsigned char	*b;

	b = (unsigned char*)str;
	while (len > 0)
	{
		*b = i;
		b++;
		len--;
	}
	return (str);
}
