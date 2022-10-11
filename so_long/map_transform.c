/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:54:33 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/10/06 23:53:37 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_opt *game, char *map)
{
	int		fd;
	char	*piece;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error("Map read Error", game);
	piece = get_next_line(fd);
	if (piece == NULL || piece[0] == '\n' )
		error1("no map");
	map_read_plus(game, piece);
	while (piece)
	{
		free(piece);
		piece = get_next_line(fd);
		if (piece && piece[0] != '\n' && piece[0] != 0)
		{
			game->perfect_map = map_connect(game->perfect_map, piece, game);
			game->hei ++;
		}
		else
			break ;
	}
	free(piece);
	close (fd);
}

void	map_read_plus(t_opt *game, char *piece)
{
	game->wid = ft_strlen(piece) - 1;
	game->hei = 1;
	game->perfect_map = map_init(piece);
	game->get = 0;
}

void	map_check_wall_shape(t_opt *game)
{
	int	i;

	i = 0;
	if (game->hei * game->wid != (int)ft_strlen(game->perfect_map) - 1)
		error("map is not rectangular", game);
	while (i < game->wid)
	{
		if (game->perfect_map[i] != '1')
			error("map is not closed", game);
		if (game->perfect_map[ft_strlen(game->perfect_map) - i - 2] != '1')
			error("map is not closed", game);
		i ++;
	}
	i = 1;
	while (i < game->hei)
	{
		if (game->perfect_map[(game->wid) * i] != '1')
			error("map is not closed", game);
		if (game->perfect_map[(game->wid) * (i + 1) - 1] != '1')
			error("map is not closed", game);
		i ++;
	}
}

void	map_check_component(t_opt *game)
{
	int	i;
	int	exit;
	int	player;

	i = 0;
	exit = 0;
	player = 0;
	game->collect = 0;
	while (i < game->wid * game->hei)
	{
		if (game->perfect_map[i] != '0' && game->perfect_map[i] != '1' && \
		game->perfect_map[i] != 'C' && game->perfect_map[i] != 'P' \
		&& game->perfect_map[i] != 'E')
			error("map has undefined value", game);
		if (game->perfect_map[i] == 'C')
			game->collect ++;
		if (game->perfect_map[i] == 'E')
			exit ++;
		if (game->perfect_map[i] == 'P')
			player ++;
		i ++;
	}
	if (player != 1 || exit < 1 || game->collect < 1)
		error("map has 1 Player, exit, collect", game);
}

void	map_check(t_opt *game)
{
	map_check_wall_shape(game);
	map_check_component(game);
}
