/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:01:01 by myson             #+#    #+#             */
/*   Updated: 2022/05/16 17:57:42 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	length;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	length = ft_strlen(substr);
	if (*substr == 0x00)
		return ((char *)str);
	if (n == 0 || *str == 0x00)
		return (0x00);
	while (i <= n - length && str[i] != 0x00)
	{
		j = 0;
		while (j + i <= n)
		{
			if (str[i + j] == substr[j] && j < length)
				j++;
			else 
				break;
		}
		if (j == length)
			return ((char *)str + i);
		i ++;
	}
	return (0x00);
}