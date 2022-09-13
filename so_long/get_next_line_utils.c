/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:53:45 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/09/06 11:01:44 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != 0x00)
	{
		new[i] = s1[i];
		i ++;
	}
	while (s2[j] != 0x00)
	{
		new[i + j] = s2[j];
		j ++;
	}
	new[i + j] = 0x00;
	return (new);
}

void	ft_free(char *str)
{
	free(str);
	str = NULL;
}
