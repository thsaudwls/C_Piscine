/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:18:02 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/10/06 23:51:52 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	image_init(void *mlx)
{
	t_img	image;
	int		wid;
	int		hei;

	image.p = mlx_xpm_file_to_image(mlx, "./images/p.xpm", &wid, &hei);
	image.c = mlx_xpm_file_to_image(mlx, "./images/c.xpm", &wid, &hei);
	image.e1 = mlx_xpm_file_to_image(mlx, "./images/e1.xpm", &wid, &hei);
	image.e2 = mlx_xpm_file_to_image(mlx, "./images/e2.xpm", &wid, &hei);
	image.f = mlx_xpm_file_to_image(mlx, "./images/f.xpm", &wid, &hei);
	image.w = mlx_xpm_file_to_image(mlx, "./images/w.xpm", &wid, &hei);
	return (image);
}

void	image_print_window(t_opt *game, int wid, int hei)
{
	if (game->perfect_map[hei * game->wid + wid] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img.w, wid * 64, hei * 64);
	else if (game->perfect_map[hei * game->wid + wid] == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img.f, wid * 64, hei * 64);
	else if (game->perfect_map[hei * game->wid + wid] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img.c, wid * 64, hei * 64);
	else if (game->perfect_map[hei * game->wid + wid] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img.p, wid * 64, hei * 64);
	else if (game->perfect_map[hei * game->wid + wid] == 'E' \
	&& game->collect != game->get)
		mlx_put_image_to_window(game->mlx, game->win, game->img.e1, \
		wid * 64, hei * 64);
	else if (game->perfect_map[hei * game->wid + wid] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.e2, \
		wid * 64, hei * 64);
}

void	image_window(t_opt *game)
{
	int	hei;
	int	wid;

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
