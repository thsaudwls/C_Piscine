/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:53:48 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/07/15 20:44:18 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newline(const char *buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (1);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *buffer, char *tmp, char *buf)
{
	int	read_len;

	while (1)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == -1)
			return (NULL);
		buffer[read_len] = '\0';
		tmp = buf;
		if (tmp == NULL)
		{
			tmp = (char *)malloc(sizeof(char) * 1);
			if (tmp == NULL)
				return (NULL);
			tmp[0] = '\0';
		}
		buf = ft_strjoin(tmp, buffer);
		ft_free(tmp);
		if (read_len == 0 || ft_newline(buf) == -1 || read_len < BUFFER_SIZE)
			break ;
	}
	ft_free(buffer);
	return (buf);
}

char	*null_fin(const char *buf)
{
	int		i;
	char	*temp;

	i = 0;
	if (buf == NULL || buf[0] == '\0')
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1 + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		temp[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		temp[i] = '\n';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_next(char *buf)
{
	int		i;
	int		n;
	char	*temp;

	if (buf == NULL)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i ++;
	if (buf[i] == '\0')
	{
		ft_free(buf);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (temp == NULL)
		return (NULL);
	i ++;
	n = 0;
	while (buf[i] != '\0')
		temp[n ++] = buf[i ++];
	temp[n] = '\0';
	ft_free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*buffer;
	char		*tmp;
	char		*value;

	tmp = NULL;
	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	buf = ft_read(fd, buffer, tmp, buf);
	if (buf == NULL)
	{
		ft_free(buffer);
		return (NULL);
	}
	value = null_fin(buf);
	buf = ft_next(buf);
	return (value);
}
