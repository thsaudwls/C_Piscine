/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:55:11 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 03:21:12 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (0x00);
	while (len < n && (str1 != 0x00 && str2 != 0x00))
	{
		if ((unsigned char)str1[len] != (unsigned char)str2[len])
			return ((unsigned char)str1[len] - (unsigned char)str2[len]);
		len ++;
	}
	return (0);
}