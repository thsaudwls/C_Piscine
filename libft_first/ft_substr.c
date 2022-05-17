/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:18:56 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 14:59:32 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char	*new;

	i = 0;
	if (*s == 0x00)
		return (0x00);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == 0x00)
		return (0x00);
	while (i < len && s[start + i] != 0x00)
	{
		new[i] = s[start + i];
		i ++;
	}
	new[i] = 0x00;
	return (new);
}