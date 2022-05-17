/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:58:32 by myson             #+#    #+#             */
/*   Updated: 2022/03/11 17:34:26 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;
	char	*new;

	new = (char *)ptr;
	i = 0;
	while (i < num)
	{
		new[i] = (unsigned char)value;
		i++;
	}
	return ((void *)new);
}
