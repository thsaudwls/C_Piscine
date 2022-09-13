/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:54:33 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/09/07 19:56:58 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    error(char *str)
{
    write(1, "*** ", 4);
    write(1, str, ft_strlen(str));
    write(1, " *** ", 4);
    exit(1);
}

void map_read(t_opt *game, char *map)
{
    int     fd;
    char    *piece;

    fd = open(map, O_RDONLY);
    if (fd < 0)
        error("Map read Error");
    piece = get_next_line(fd);
    game->wid = ft_strlen(piece) - 1;
    game->hei = 0;
    game->perfect_map = map_init(piece);
    game->get = 0;
    free(piece);
    while (piece)
    {
        piece = get_next_line(fd);
        if (piece)
            game->perfect_map = map_connect(game->perfect_map, piece);
        game->hei ++;
        // if (piece[ft_strlen(piece) - 1] != '\n')
        //     break;
    }
    close (fd);
}

void    map_check_wall_shape(t_opt *game)
{
    int i;

    i = 0;
    if (game->hei * game->wid != (int)ft_strlen(game->perfect_map))
        error("shape of map is not rectangle");
    while (i < game->wid)
    {
        if (game->perfect_map[i] != '1')
            error("map is not closed");
        if (game->perfect_map[ft_strlen(game->perfect_map) - i - 1] != '1')
            error("map is not closed");
        i ++;
    }
    i = 1;
    while (i < game->hei)
    {
        if (game->perfect_map[(game->wid) * i] != '1')
            error("map is not closed");
        if (game->perfect_map[(game->wid) * (i + 1) - 1 ] != '1')
            error("map is not closed");
        i ++;
    }
}   

void    map_check_component(t_opt *game)
{
    int i;
    int exit;
    int player;

    i = 0;
    exit = 0;
    player = 0;
    game->collect = 0;

    while (i < game->wid * game->hei)
    {
        if (game->perfect_map[i] == 'C')
            game->collect ++;
        if (game->perfect_map[i] == 'E')
            exit ++;
        if (game->perfect_map[i] == 'P')
            player ++;
        i ++;
    }
    if (player != 1)
        error("There must be 1 player.");
    if (exit < 1)
        error("There is no exit");
    if (game->collect < 1)
        error("There is no collect");
}

void    map_check(t_opt *game)
{
    map_check_wall_shape(game);
    map_check_component(game);
}
