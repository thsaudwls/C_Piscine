/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:56:44 by myson             #+#    #+#             */
/*   Updated: 2022/05/03 01:20:50 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;
	unsigned char	*ori;

	count = 0;
	ori = (unsigned char *)s;
	while (count < n)
	{
		if (ori[count] == (unsigned char)c)
			return (&ori[count]);
		count ++;
	}
	return ((void *)0);
}
