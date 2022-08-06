/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:17:43 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/04 16:41:14 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_c(va_list **ap)
{
	unsigned char	tmp;

	tmp = (unsigned char)va_arg(**ap, int);
	write(1, &tmp, 1);
	return (1);
}

int	printf_s(va_list **ap)
{
	char	*tmp;

	tmp = va_arg(**ap, char *);
	if (tmp == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, tmp, ft_strlen(tmp));
	return (ft_strlen(tmp));
}


int printf_percent(void)
{
    write(1, "%%", 1);
	return (1);
}
