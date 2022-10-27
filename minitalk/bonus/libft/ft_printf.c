/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:49:46 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/10 22:09:50 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int *error)
{
	int	len;

	if (*error == 1)
		return (-1);
	len = write(1, &c, 1);
	if (len < 0)
		*error = 1;
	return (1);
}

int	print_s(char *str, int *error)
{
	int	write_rslt;
	int	result;

	if (*error == 1)
		return (-1);
	if (str == 0)
	{
		write_rslt = write(1, "(null)", 6);
		if (write_rslt < 0)
			*error = 1;
		return (6);
	}
	result = 0;
	while(*str)
	{
		write_rslt = ft_putchar(*(str ++), error);
		if (write_rslt < 0)
			*error = 1;
		result += write_rslt;
	}
	return (result);
}

int	print_cal(char args, va_list *ap, int *error)
{
	int	len;

	len = 0;
	if (args == 'c')
		len += ft_putchar(va_arg(*ap, int), error);
	else if (args == 's')
		len += print_s(va_arg(*ap, char *), error);
	else if (args == 'p')
		len += print_addr(va_arg(*ap, void *), error);
	else if (args == 'd' || args == 'i')
		len += print_int(va_arg(*ap, int), error);
	else if (args == 'u')
		len += print_uint(va_arg(*ap, unsigned int), error);
	else if (args == 'x')
		len += print_x(va_arg(*ap, unsigned int), error);
	else if (args == 'X')
		len += print_big_x(va_arg(*ap, unsigned int), error);
	else if (args == '%')
		len += ft_putchar('%', error);
	return (len);
}

int	pre_printf(const char *args, va_list ap, int *error)
{
	int	cnt;

	cnt = 0;
	while (*args != '\0')
	{
		if (*args == '%')
		{
			args ++;
			cnt += print_cal(*args, &ap, error);
		}
		else
			cnt += ft_putchar(*args, error);
		args ++;
	}
	return (cnt);
}

int	ft_printf(const char *args, ...)
{
    va_list	ap;
	int		result;
	int		*error;
	int		i;
	
	i = 0;
	error = &i;
	result = 0;
	va_start(ap, args);
	result = pre_printf((char *)args, ap, error);
	va_end(ap);
	if (*error == 1)
		return (-1);
	return (result);
}