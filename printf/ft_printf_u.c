/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:51:59 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/04 17:14:02 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_num(unsigned int num)
{
	char	rst[12];
	int		i;
	int		cnt;

	cnt = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		rst[cnt] = num % 10 + '0';
		num = num / 10;
		cnt ++;
	}
	i = cnt;
	while (i > 0)
	{
		write(1, &rst[i - 1], 1);
		i --;
	}
	return (cnt);
}

int printf_u(va_list **ap)
{
    unsigned int	tmp;
	int				cnt;

	tmp = (unsigned int)va_arg(**ap, unsigned int);
	cnt = write_num(tmp);
	return (cnt);
}