/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:03:32 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 19:57:18 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_in_set(char const *set, char c);

char	*ft_new(void)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * 1);
	if (!new)
		return (0x00);
	new[0] = 0;
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	j = 0;
	count = 0;
	if (s1 == 0x00 || set == 0x00)
		return (0x00);
	while (find_in_set(set, s1[i]) == 1)
		i ++;
	if (i == ft_strlen(s1))
		return (ft_new());
	while (find_in_set(set, s1[ft_strlen(s1) - j - 1]) == 1)
		j ++;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) - j - i) + 1);
	if (new == 0x00)
		return (0x00);
	while (i < ft_strlen(s1) - j)
		new[count++] = s1[i++];
	new[count] = 0x00;
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
