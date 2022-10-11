/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manipulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:40:30 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/10/06 23:51:55 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_opt *game)
{
	char	*num;

	num = ft_itoa(game->step_num);
	if (key == KEY_U)
		move_up(game);
	else if (key == KEY_D)
		move_down(game);
	else if (key == KEY_R)
		move_right(game);
	else if (key == KEY_L)
		move_left(game);
	else if (key == KEY_ESC)
		quit_game(game);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "steps : ");
	mlx_string_put(game->mlx, game->win, 85, 10, 0xFFFFFF, num);
	free(num);
	return (0);
}

void	move_up(t_opt *game)
{
	int	i;

	i = 0;
	while (i < game->wid * game->hei)
	{
		if (game->perfect_map[i] == 'P')
			break ;
		i ++;
	}
	if (game->perfect_map[i - game->wid] == 'E' && game->collect == game->get)
	{
		game->step_num ++;
		quit_game(game);
	}
	if (game->perfect_map[i - game->wid] == 'C')
		game->get ++;
	if (game->perfect_map[i - game->wid] != '1' && \
		game->perfect_map[i - game->wid] != 'E')
	{
		game->step_num ++;
		game->perfect_map[i] = '0';
		game->perfect_map[i - game->wid] = 'P';
		printf("%d\n", game->step_num);
		image_window(game);
	}
}

void	move_down(t_opt *game)
{
	int	i;

	i = 0;
	while (i < game->wid * game->hei)
	{
		if (game->perfect_map[i] == 'P')
			break ;
		i ++;
	}
	if (game->perfect_map[i + game->wid] == 'E' && game->collect == game->get)
	{
		game->step_num ++;
		quit_game(game);
	}
	if (game->perfect_map[i + game->wid] == 'C')
		game->get ++;
	if (game->perfect_map[i + game->wid] != '1' \
		&& game->perfect_map[i + game->wid] != 'E')
	{
		game->step_num ++;
		game->perfect_map[i] = '0';
		game->perfect_map[i + game->wid] = 'P';
		printf("%d\n", game->step_num);
		image_window(game);
	}
}

void	move_right(t_opt *game)
{
	int	i;

	i = 0;
	while (i < game->wid * game->hei)
	{
		if (game->perfect_map[i] == 'P')
			break ;
		i ++;
	}
	if ((i + 1) / game->wid == i / game->wid)
	{
		if (game->perfect_map[i + 1] == 'E' && game->collect == game->get)
			step_plus(game);
		if (game->perfect_map[i + 1] == 'C')
			game->get ++;
		if (game->perfect_map[i + 1] != '1' && game->perfect_map[i + 1] != 'E')
		{
			game->step_num ++;
			game->perfect_map[i] = '0';
			game->perfect_map[i + 1] = 'P';
			printf("%d\n", game->step_num);
			image_window(game);
		}
	}
}

void	move_left(t_opt *game)
{
	int	i;

	i = 0;
	while (i < game->wid * game->hei)
	{
		if (game->perfect_map[i] == 'P')
			break ;
		i ++;
	}
	if ((i - 1) / game->wid == i / game->wid)
	{
		if (game->perfect_map[i - 1] == 'E' && game->collect == game->get)
			step_plus(game);
		if (game->perfect_map[i - 1] == 'C')
			game->get ++;
		if (game->perfect_map[i - 1] != '1' && game->perfect_map[i - 1] != 'E')
		{
			game->step_num ++;
			game->perfect_map[i] = '0';
			game->perfect_map[i - 1] = 'P';
			printf("%d\n", game->step_num);
			image_window(game);
		}
	}
}
