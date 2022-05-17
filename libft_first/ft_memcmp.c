/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:59:27 by myson             #+#    #+#             */
/*   Updated: 2022/05/03 01:23:11 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dst, const void *src, size_t n)
{
	unsigned char	*dst_new;
	unsigned char	*src_new;
	size_t	count;

	dst_new = (unsigned char *)dst;
	src_new = (unsigned char *)src;
	count = 0;
	while (count < n)
	{
		if (dst_new[count] != src_new[count])
			return (dst_new[count] - src_new[count]);
		count ++;
	}
	return (0);
}
