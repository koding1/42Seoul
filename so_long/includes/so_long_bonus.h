/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:50:19 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 21:00:11 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <errno.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../mlx_opengl/mlx.h"
# include "./gnl/get_next_line.h"
# include "./error_bonus.h"

# define KEY_ESC 53
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define KEY_PRESS 2
# define GAME_WINDOW_EXIT 17

# define P_CODE 32
# define C_CODE 19
# define E_CODE 21

# define WALL_IMAGE_PATH "./imgs/wooden.xpm"
# define GRASS_IMAGE_PATH "./imgs/grass.xpm"
# define CAT_IMAGE_PATH "./imgs/cat.xpm"
# define CHEST_IMAGE_PATH "./imgs/chest.xpm"
# define EXIT_O_IMAGE_PATH "./imgs/exit_o.xpm"
# define EXIT_X_IMAGE_PATH "./imgs/exit_x.xpm"
# define FISH_IMAGE_PATH "./imgs/fish.xpm"

# define ZERO_IMAGE_PATH "./imgs/num_img/0.xpm"
# define ONE_IMAGE_PATH "./imgs/num_img/1.xpm"
# define TWO_IMAGE_PATH "./imgs/num_img/2.xpm"
# define THREE_IMAGE_PATH "./imgs/num_img/3.xpm"
# define FOUR_O_IMAGE_PATH "./imgs/num_img/4.xpm"
# define FIVE_X_IMAGE_PATH "./imgs/num_img/5.xpm"
# define SIX_IMAGE_PATH "./imgs/num_img/6.xpm"
# define SEVEN_IMAGE_PATH "./imgs/num_img/7.xpm"
# define EIGHT_IMAGE_PATH "./imgs/num_img/8.xpm"
# define NINE_IMAGE_PATH "./imgs/num_img/9.xpm"

# define CAT1_IMAGE_PATH "./imgs/cat/cat1.xpm"
# define CAT2_IMAGE_PATH "./imgs/cat/cat2.xpm"
# define CAT3_IMAGE_PATH "./imgs/cat/cat3.xpm"
# define CAT4_IMAGE_PATH "./imgs/cat/cat4.xpm"

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		img_w;
	int		img_h;
	int		visibility;
}	t_img_data;

typedef struct s_position {
	int	x;
	int	y;
}	t_position;

typedef struct s_map {
	int		w;
	int		h;
	int		**data;
	char	*map_str;
}	t_map;

typedef struct s_game {
	t_map		map;
	t_position	char_po;
	t_img_data	wall;
	t_img_data	grass;
	t_img_data	chest;
	t_img_data	cat;
	t_img_data	exit_o;
	t_img_data	exit_x;
	t_img_data	fish;
	t_img_data	num[10];
	t_img_data	cats[4];
	t_data_cnt	cnts;
	void		*mp;
	void		*wp;
}	t_game;

int		draw_cat_sprite(t_game *game);
void	draw_cat_normal(t_game g, int i, int j);
void	move_cat_draw(t_game *game, int dx, int dy);

int		key_press(int keycode, t_game *game_info);
int		exit_game(t_game *game);

int		game_init(t_game *g, char *map_name);

void	image_set(t_game *game);

void	draw_grass(t_game g, int i, int j);
int		map_draw(t_game game_info);

void	move_cat(t_game *game, int dx, int dy);

int		rect_checker(t_game *game, char *one_line);
void	wall_checker(t_game *game);
void	exist_checker(t_game *game);
void	is_valid_map(t_game *game);
void	error_check(int code);

void	move_cnt_draw(t_game game);

void	read_map_file(t_game *game, char *map_name);

#endif
