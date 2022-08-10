/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:50:53 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/10 22:09:52 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

int	print_x(unsigned long long hex, int *error);
int	print_big_x(unsigned long long hex, int *error);
int	print_addr(void *addr, int *error);
int	print_int(int num, int *error);
int	print_uint(unsigned int num, int *error);
int	ft_putchar(int c, int *error);
int	print_s(char *str, int *error);
int	print_cal(char args, va_list *ap, int *error);
int	pre_printf(const char *args, va_list ap, int *error);
int	ft_printf(const char *args, ...);

#endif