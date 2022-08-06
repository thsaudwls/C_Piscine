/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:55:11 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 18:23:13 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (0x00);
	while ((str1[len] != 0x00 || str2[len] != 0x00) && len < n)
	{
		if ((unsigned char)str1[len] != (unsigned char)str2[len])
			return ((unsigned char)str1[len] - (unsigned char)str2[len]);
		len ++;
	}
	return (0);
}
