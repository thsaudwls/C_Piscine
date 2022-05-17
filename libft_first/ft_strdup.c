/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:06:13 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 14:09:33 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	int		copy_len;
	char	*copy_str;

	len = ft_strlen(str);
	copy_len = 0;
	copy_str = (char *)malloc(sizeof(char) * len + 1);
	if (copy_str == 0x00)
		return (0x00);
	while (str[copy_len] != 0x00)
	{
		copy_str[copy_len] = str[copy_len];
		copy_len ++;
	}
	copy_str[copy_len] = 0x00;
	return (copy_str);
}
