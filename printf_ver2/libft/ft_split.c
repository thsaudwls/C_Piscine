/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:44:44 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/05/17 20:08:25 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*new;

	i = 0;
	new = 0x00;
	if (n == 0)
		return (new);
	new = (char *)malloc(sizeof(char) * (n + 1));
	if (new == 0x00)
		return (0x00);
	while (i < n)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0x00;
	return (new);
}

char	**free_a(char **new)
{
	size_t	i;

	i = 0;
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free(new);
	return (0x00);
}

size_t	count_word(char const *s, char c)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (s[i] != 0x00)
	{
		if ((i == 0 && s[i] != c))
			size ++;
		if (s[i] == c && s[i + 1] != 0x00 && s[i + 1] != c)
			size ++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (s == 0x00)
		return (0x00);
	new = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (new == 0x00)
		return (0x00);
	while (i < count_word(s, c) && s[j] != 0x00)
	{
		while (s[j] == c)
			j++;
		len = j;
		while (s[j] != c && s[j] != 0x00)
			j++;
		new[i] = ft_strndup(&s[len], j - len);
		if (new[i++] == 0x00)
			return (free_a(new));
	}
	new[i] = 0x00;
	return (new);
}
