/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:50:13 by myson             #+#    #+#             */
/*   Updated: 2022/05/13 10:31:51 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != 0x00)
		dst_len ++;
	while (src[src_len] != 0x00 && (src_len + dst_len + 1) < len)
	{
		dst[dst_len + src_len] = src[src_len];
		src_len ++;
	}
	dst[dst_len + src_len] = 0x00;
	while (src[src_len] != 0x00)
		src_len ++;
	if (dst_len > len)
		return (src_len + len);
	return (dst_len + src_len);
}
