/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myson <myson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:33:10 by rnyeong._.j       #+#    #+#             */
/*   Updated: 2022/10/06 23:39:32 by myson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"

# define KEY_U 13
# define KEY_D 1
# define KEY_R 2
# define KEY_L 0
# define KEY_ESC 53

# define KEY_EXIT		17
# define KEY_PRESS		2

typedef struct s_img {
	void	*p;
	void	*e1;
	void	*e2;
	void	*w;
	void	*f;
	void	*c;
}	t_img;

typedef struct s_opt {
	void	*win;
	void	*mlx;
	t_img	img;
	char	*perfect_map;
	int		step_num;
	int		hei;
	int		wid;
	int		collect;
	int		get;
}	t_opt;

t_img	image_init(void *mlx);
void	image_print_window(t_opt *game, int hei, int wid);
void	image_window(t_opt *game);
int		key_press(int key, t_opt *game);
void	move_up(t_opt *game);
void	move_down(t_opt *game);
void	move_right(t_opt *game);
void	move_left(t_opt *game);
void	error(char *str, t_opt *game);
void	map_read(t_opt *game, char *map);
void	map_check_wall_shape(t_opt *game);
void	map_check_component(t_opt *game);
void	map_check(t_opt *game);
int		quit_game(t_opt *game);
void	init_game(t_opt *game);
char	*map_init(char *first_line_map);
char	*map_connect(char *s1, char *s2, t_opt *game);
char	*final_map(char *map, t_opt *game);
void	error1(char *str);
void	map_read_plus(t_opt *game, char *piece);
int		bf_line(char *s1);
void	step_plus(t_opt *game);

#endif