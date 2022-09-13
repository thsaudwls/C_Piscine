/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:03:21 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/09/07 20:08:44 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int quit_game(t_opt *game)
{
    mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void    init_game(t_opt *game, char *map)
{
    game->mlx = mlx_init();
	game->img = image_init(game->mlx);
	map_read(game, map);
	map_check(game);
	game->win = mlx_new_window(game->mlx, game->wid * 64, game->hei * 64, "so_long");
	image_window(game);
}

int main(int argc, char *argv[])
{
    t_opt   *game;

    if (argc != 2)
        error("argc error");
    game = (t_opt *)malloc(sizeof(t_opt));
    init_game(game, argv[1]);
	mlx_hook(game->win, KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, KEY_EXIT, 0, &quit_game, game);
	mlx_loop(game->mlx);
	return (0);
}