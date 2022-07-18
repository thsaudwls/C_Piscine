/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:53:45 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/07/15 20:46:26 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0x00)
		i ++;
	return (i);
}

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
