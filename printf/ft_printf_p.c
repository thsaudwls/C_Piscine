/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:32:02 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/04 17:37:56 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	change_hex(unsigned long long num)
{
	int		cnt;
	int		i;
	char	rst[20];

	cnt = 0;
	write(1, "0x", 2);
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

// int	change_hex(unsigned long long add, int *cnt)
// {
//     char	tmp[16];
// 	int		i;
// 	int		temp;

// 	i = 9;

// 	while (i > 1)
// 	{
// 		temp = add % 16;
// 		if (temp > 9)
// 			tmp[i] = 'a' + temp - 10;
// 		else
// 			tmp[i] = temp + '0';
// 		add = add / 16;
// 		i --;
// 		cnt ++;
// 	}
// 	tmp[i] = 'x';
// 	tmp[i - 1] = '0';
// 	write(1, &tmp[i - 1], (*cnt) + 2);

// 	return (0);
// }

int printf_p(va_list **ap)
{
    unsigned long long	tmp;
	int					cnt;

    tmp = (unsigned long long)va_arg(**ap, unsigned long long);
	if (tmp == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
    cnt = change_hex(tmp);
    return(cnt + 2);
}