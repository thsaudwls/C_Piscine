/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:49:04 by myson             #+#    #+#             */
/*   Updated: 2022/05/03 01:57:36 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
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
