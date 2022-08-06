/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:18:40 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 16:09:52 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const void	*s;
	void		*d;
	size_t		i;

	s = src;
	d = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (d > s)
	{
		while (len-- > 0)
			((unsigned char *)d)[len] = ((unsigned char *)s)[len];
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)d)[i] = ((unsigned char *)s)[i];
			i++;
		}
	}
	return (dst);
}
