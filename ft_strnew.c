/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:10:02 by mabanciu          #+#    #+#             */
/*   Updated: 2018/01/11 16:34:11 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(size)))
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
