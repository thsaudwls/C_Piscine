/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:03:55 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/04 16:41:13 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cnt_zero(unsigned int num)
{
	int cnt;

	cnt = 1;
	while (num >= 10)
	{
		num = num / 10;
		cnt *= 10;
	}
	return (cnt);
}

int	ft_len(unsigned int num)
{
	int len;

	len = 1;
	while (num >= 10)
	{
		num = num / 10;
		len ++;
	}
	return (len);
}

int write_num_o(unsigned int num, int zero, int len, int sign)
{
	char	value[15];
	int		i;
	int		minus;

	i = 0;
	minus = '-';
	while (i < len)
	{
		value[i ++] = num / zero + '0';
		num = num % zero;
		zero = zero / 10;
	}
	i = 0;
	if (sign == 1)
		write(1, &minus, 1);
	while (i < len)
		write(1, &value[i++], 1);
	return (i + sign);
}

int	ft_putnbr_n(int number)
{
	unsigned int	num;
	int				sign;
	int				result;

	sign = 0;
	if (number < 0 && number >= -2147483638)
	{
		sign = 1;
		num = number * -1;
	}
	else if (number >= 0 && number <= 2147483647)
		num = number;
	else if (number == -2147483648)
	{
		num = 2147483648;
		sign = 1;
	}
	else if (number < -2147483648)
		num = 0;
	else
	{
		num = 1;
		sign = 1;
	}
	result = (write_num_o(num, cnt_zero(num), ft_len(num), sign));
	return (result);
}

int printf_d(va_list **ap)
{
    int tmp;

    tmp = va_arg(**ap, int);
    return (ft_putnbr_n(tmp));
}
