/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:03:21 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/10/06 23:59:09 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bf_line(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\n' && s1[i])
		i ++;
	return (i);
}

void	step_plus(t_opt *game)
{
	game->step_num ++;
	quit_game(game);
}

int	quit_game(t_opt *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->perfect_map);
	exit(0);
}

void	init_game(t_opt *game)
{
	game->mlx = mlx_init();
	game->img = image_init(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_opt	*game;
	char	*num;

	if (argc != 2)
		error1("argc error");
	game = (t_opt *)malloc(sizeof(t_opt));
	init_game(game);
	map_read(game, argv[1]);
	map_check(game);
	game->win = mlx_new_window(game->mlx, game->wid * 64, \
		game->hei * 64, "so_long");
	image_window(game);
	num = ft_itoa(game->step_num);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "steps : ");
	mlx_string_put(game->mlx, game->win, 85, 10, 0xFFFFFF, num);
	free(num);
	mlx_hook(game->win, KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, KEY_EXIT, 0, &quit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
