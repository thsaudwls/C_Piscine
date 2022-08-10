/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:53:51 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 03:16:39 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	char	*rem;

	rem = 0x00;
	ch = (char)c;
	if (ch == 0x00)
	{
		return ((char *)str + ft_strlen(str));
	}
	while (*str != 0x00)
	{
		if ((char)*str == ch)
			rem = ((char *)str);
		str ++;
	}
	return (rem);
}
