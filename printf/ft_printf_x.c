/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:15:19 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/04 17:21:02 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_x(unsigned int num)
{
	int		cnt;
	char	rst[20];
	int		i;

	cnt = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		if (num % 16 > 9)
			rst[cnt] = num % 16 - 10 + 'a';
		else
			rst[cnt] = num % 16 + '0';
		num = num / 16;
		cnt ++;
	}
	i = cnt;
	while (cnt > 0)
	{
		write(1, &rst[cnt - 1], 1);
		cnt --;
	}
	return (i);
}

int printf_x(va_list **ap)
{
	unsigned int	tmp;

	tmp = (unsigned int)va_arg(**ap, unsigned int);
	return (len_x(tmp));
}

int	len_X(unsigned int num)
{
	int		cnt;
	char	rst[20];
	int		i;

	cnt = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		if (num % 16 > 9)
			rst[cnt] = num % 16 - 10 + 'A';
		else
			rst[cnt] = num % 16 + '0';
		num = num / 16;
		cnt ++;
	}
	i = cnt;
	while (cnt > 0)
	{
		write(1, &rst[cnt - 1], 1);
		cnt --;
	}
	return (i);
}

int printf_X(va_list **ap)
{
	unsigned int	tmp;

	tmp = va_arg(**ap, unsigned int);
	return (len_X(tmp));
}

