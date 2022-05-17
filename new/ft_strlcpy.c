/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:49:04 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 19:56:16 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	count;

	len = 0;
	count = 0;
	while (src[len] != 0x00)
		len ++;
	if (size == 0)
		return (len);
	while (count < size - 1 && src[count] != 0x00)
	{
		dest[count] = src[count];
		count ++;
	}
	dest[count] = 0x00;
	return (len);
}
