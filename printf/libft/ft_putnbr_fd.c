/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:36:08 by myson             #+#    #+#             */
/*   Updated: 2022/05/16 16:29:57 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[11];
	int		i;
	long	large_limit;

	i = 0;
	large_limit = (long)n;
	if (n < 0)
		write(fd, "-", 1);
	if (n == -2147483648)
		write(fd, "2147483648", 10);
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0 && n != -2147483648)
		n *= -1;
	while (n > 0)
	{
		num[i] = n % 10 + '0';
		n = n / 10;
		i ++;
	}
	while (i > 0)
	{
		write(fd, &num[i - 1], 1);
		i --;
	}
}
