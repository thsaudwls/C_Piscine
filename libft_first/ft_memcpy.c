/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:18:40 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 16:09:52 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ori;
	char	*new;
	size_t	i;

	if (dst == src)
		return (dst);
	ori = (char *)src;
	new = (char *)dst;
	i = 0;
	while (i < n)
	{
		new[i] = ori[i];
		i ++;
	}
	return (dst);
}
