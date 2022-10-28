/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:31:23 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/10/27 15:32:05 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_accept(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("your input = wrong format.\n");
		ft_printf("Try again : ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID = [%d]\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_accept);
		signal(SIGUSR2, ft_accept);
		pause ();
	}
	return (0);
}
