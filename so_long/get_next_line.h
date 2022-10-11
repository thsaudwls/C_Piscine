/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:53:50 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/10/06 23:04:39 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_newline(const char *buf);
char	*ft_read(int fd, char *buffer, char *tmp, char *buf);
char	*null_fin(const char *buf);
char	*ft_next(char *buf);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_free(char *str);

#endif