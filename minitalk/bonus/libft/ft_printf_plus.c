/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 21:21:42 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/10 22:09:51 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned long long hex, int *error)
{
	int	rslt;

	if (hex < 16)
		return (ft_putchar("0123456789abcdef"[hex], error));
	else
	{
		rslt = print_x(hex / 16, error);
		return (rslt + ft_putchar("0123456789abcdef"[hex % 16], error));
	}
}

int	print_big_x(unsigned long long hex, int *error)
{
	int	rslt;

	if (hex < 16)
		return (ft_putchar("0123456789ABCDEF"[hex], error));
	else
	{
		rslt = print_big_x(hex / 16, error);
		return (rslt + ft_putchar("0123456789ABCDEF"[hex % 16], error));
	}
}

int	print_addr(void *addr, int *error)
{
	int	rslt;

	rslt = 0;
	rslt += print_s("0x", error);
	rslt += print_x((unsigned long long)addr, error);
	return (rslt);
}

int	print_int(int num, int *error)
{
	int	rslt;

	rslt = 0;
	if (num == -2147483648)
		return (print_s("-2147483648", error));
	else if (num == 0)
		return (ft_putchar('0', error));
	else if (num < 0)
	{
		rslt += ft_putchar('-', error);
		num = num * -1;
	}
	rslt += print_uint(num, error);
	return (rslt);
}

int	print_uint(unsigned int num, int *error)
{
	char	number[12];
	int		cnt;
	int		rslt;

	cnt = 0;
	rslt = 0;
	if (num == 0)
		return (ft_putchar('0', error));
	while (num > 0)
	{
		number[cnt] = num % 10 + '0';
		num = num / 10;
		cnt ++;
	}
	while (cnt > 0)
		rslt += ft_putchar(number[-- cnt], error);
	return (rslt);
}
