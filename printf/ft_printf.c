/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:13:23 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/04 16:41:10 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

int ft_check_and_len(const char *args, int *i, va_list *ap)
{
	int len;

	len = 0;
	if (args[*i] == 'c')
		len = printf_c(&ap);
	else if (args[*i] == 's')
		len = printf_s(&ap);
	else if (args[*i] == 'p')
		len = printf_p(&ap);
	else if (args[*i] == 'd')
		len = printf_d(&ap);
	else if (args[*i] == 'i')
		len = printf_d(&ap);
	else if (args[*i] == 'u')
		len = printf_u(&ap);
	else if (args[*i] == 'x')
		len = printf_x(&ap);
	else if (args[*i] == 'X')
		len = printf_X(&ap);
	else if (args[*i] == '%')
		len = printf_percent();
	return (len);
}

int print_basic(const char *args, va_list ap)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (args[i] != '\0')
	{
		if (args[i] == '%')
		{
			i ++;
			cnt += ft_check_and_len(args, &i, &ap);
		}
		else
		{
			ft_putchr(args[i]);
			cnt ++;
		}
		i ++;
	}
	return (cnt);
}

int	ft_printf(const char *args, ...)
{
	int		rt_len;
	va_list ap;

	rt_len = 0;
	va_start(ap, args);
	rt_len = print_basic(args, ap);
	va_end(ap);
	return (rt_len);
}