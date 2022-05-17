/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:30:37 by myson             #+#    #+#             */
/*   Updated: 2022/05/03 02:12:39 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s);
	i = 0;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (0x00);
	while (i < len)
	{
		new[i] = f(i, s[i]);
		i ++;
	}
	new[i] = 0x00;
	return (new);
}
