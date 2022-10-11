/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:07:00 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/10/06 23:59:05 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str, t_opt *game)
{
	write(1, "*** ", 4);
	write(1, str, ft_strlen(str));
	write(1, " *** ", 4);
	free(game->perfect_map);
	exit(1);
}

void	error1(char *str)
{
	write(1, "*** ", 4);
	write(1, str, ft_strlen(str));
	write(1, " *** ", 4);
	exit(1);
}

char	*map_init(char *first_line_map)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(first_line_map)));
	if (!new)
		return (NULL);
	while (i < (int)ft_strlen(first_line_map))
	{
		new[i] = first_line_map[i];
		i ++;
	}
	return (new);
}

char	*map_connect(char *s1, char *s2, t_opt *game)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (bf_line(s1) + bf_line(s2)) + 2);
	if (!new)
		return (NULL);
	while (s1[++i] != '\n' && s1[i])
		new[i] = s1[i];
	while (s2[j] != '\n' && s2[j])
		new[i++] = s2[j++];
	new[i] = '\n';
	new[++i] = 0;
	free(s1);
	if (j != game->wid)
	{
		free(new);
		error1("not ractangular");
	}
	return (new);
}

char	*final_map(char *map, t_opt *game)
{
	char	*new;
	int		i;

	i = 0;
	while (map[i] != '\n' && map[i])
		i ++;
	new = (char *)malloc(sizeof(char) * i);
	game->hei -= (int)ft_strlen(game->perfect_map) - i - 1;
	i = 0;
	while (map[i] != '\n')
	{
		new[i] = map[i];
		i ++;
	}
	free(map);
	return (new);
}
