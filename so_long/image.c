/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnyeong._.jin <rnyeong._.jin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:18:02 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/09/06 15:40:49 by rnyeong._.j      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img   image_init(void *mlx)
{
    t_img   image;
    int     wid;
    int     hei;

    image.P = mlx_xpm_file_to_image(mlx, "./images/P.xpm", &wid, &hei);
    image.C = mlx_xpm_file_to_image(mlx, "./images/C.xpm", &wid, &hei);
    image.E1 = mlx_xpm_file_to_image(mlx, "./images/E1.xpm", &wid, &hei);
    image.E2 = mlx_xpm_file_to_image(mlx, "./images/E2.xpm", &wid, &hei);
    image.F = mlx_xpm_file_to_image(mlx, "./images/F.xpm", &wid, &hei);
    image.W = mlx_xpm_file_to_image(mlx, "./images/W.xpm", &wid, &hei);
    return (image);
}

void    image_print_window(t_opt *game, int wid, int hei)
{
    if (game->perfect_map[hei * game->wid + wid] == '1')
        mlx_put_image_to_window(game->mlx, game->win, game->img.W, wid * 64, hei * 64);
    else if (game->perfect_map[hei * game->wid + wid] == '0')
        mlx_put_image_to_window(game->mlx, game->win, game->img.F, wid * 64, hei * 64);
    else if (game->perfect_map[hei * game->wid + wid] == 'C')
        mlx_put_image_to_window(game->mlx, game->win, game->img.C, wid * 64, hei * 64);
    else if (game->perfect_map[hei * game->wid + wid] == 'P')
        mlx_put_image_to_window(game->mlx, game->win, game->img.P, wid * 64, hei * 64);
    else if (game->perfect_map[hei * game->wid + wid] == 'E' && game->collect != game->get)
        mlx_put_image_to_window(game->mlx, game->win, game->img.E1, wid * 64, hei * 64);
    else if (game->perfect_map[hei * game->wid + wid] == 'E')
        mlx_put_image_to_window(game->mlx, game->win, game->img.E2, wid * 64, hei * 64);
}

void    image_window(t_opt *game)
{
    int hei;
    int wid;

    hei = 0;
    while (hei < game->hei)
    {
        wid = 0;
        while (wid < game->wid)
        {
            image_print_window(game, wid, hei);
            wid ++;
        }
        hei ++;
     }
}