/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:51:46 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 14:32:39 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const*s1, char const*s2)
{
	int		len1;
	int		len2;
	char	*new;
	int		i;

	i = 0;
	if (s1 == 0x00 || s2 == 0x00)
		return (0x00);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (new == 0x00)
		return (0x00);
	while (i < len1)
	{
		new[i] = s1[i];
		i ++;
	}
	while (i < len1 + len2)
	{
		new[i] = s2[i - len1];
		i ++;
	}
	new[i] = 0x00;
	return (new);
}
