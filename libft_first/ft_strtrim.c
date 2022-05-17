/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:03:32 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 14:40:13 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_in_set(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	j = 0;
	count = 0;
	while (find_in_set(set, s1[i]) == 1)
		i ++;
	if (i == ft_strlen(s1))
	{
		new = (char*)malloc(sizeof(char) * 1);
		if (!new)
			return (0x00);
		new[0] = 0;
		return (new);
	}
	while (find_in_set(set, s1[ft_strlen(s1) - j - 1]) == 1)
		j ++;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) - j - i) + 1);
	if (new == 0x00)
		return (0x00);
	while (i < ft_strlen(s1) - j)
	{
		new[count] = s1[i];
		i ++;
		count ++;
	}
	return (new);
}

int	find_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != 0x00)
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}
