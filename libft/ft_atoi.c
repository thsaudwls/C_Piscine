/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:04:19 by myson             #+#    #+#             */
/*   Updated: 2022/05/17 20:12:37 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	num;
	int			pm;
	long long	save;

	pm = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pm = -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9' && *str != 0x00)
	{
		save = num;
		num = 10 * num + (*str - '0');
		if (save > 0 && save > num && pm > 0)
			return (-1);
		if (save > 0 && save > num && pm < 0)
			return (0);
		str ++;
	}
	return (num * pm);
}
