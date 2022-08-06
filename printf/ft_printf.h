/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:09:25 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/08/04 17:38:00 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

int		printf_c(va_list **ap);
int		printf_s(va_list **ap);
int		printf_percent(void);
int		cnt_zero(unsigned int num);
int		ft_len(unsigned int num);
int		write_num_o(unsigned int num, int zero, int len, int sign);
int		ft_putnbr_n(int number);
int 	printf_d(va_list **ap);
int		change_hex(unsigned long long num);
int		printf_p(va_list **ap);
int		write_num(unsigned int num);
int		printf_u(va_list **ap);
int		len_x(unsigned int num);
int		printf_x(va_list **ap);
int		len_X(unsigned int num);
int		printf_X(va_list **ap);
int		ft_check_and_len(const char *args, int *i, va_list *ap);
int		print_basic(const char *args, va_list ap);
int		ft_printf(const char *args, ...);
void	ft_putchr(char c);

#endif


