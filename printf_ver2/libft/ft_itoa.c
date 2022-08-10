/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:51:51 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 02:09:48 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_num(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size ++;
	while (n != 0)
	{
		n = n / 10;
		size ++;
	}
	return (size);
}

char	*negative(int n, int size)
{
	char	*new_char;

	new_char = (char *)malloc(sizeof(char) * size + 1);
	if (new_char == 0x00)
		return (0);
	new_char[0] = '-';
	new_char[size] = 0x00;
	while (size > 1)
	{
		new_char[size - 1] = (n % 10) * (-1) + '0';
		n = (n / 10);
		size --;
	}
	return (new_char);
}

char	*ft_itoa(int n)
{
	char	*new_char;
	int		size;

	size = size_num(n);
	if (n < 0)
		new_char = negative(n, size);
	else
	{
		new_char = (char *)malloc(sizeof(char) * size + 1);
		if (new_char == 0x00)
			return (0);
		new_char[size] = 0x00;
		while (size > 0)
		{
			new_char[size - 1] = n % 10 + '0';
			n = n / 10;
			size --;
		}
	}
	return (new_char);
}
